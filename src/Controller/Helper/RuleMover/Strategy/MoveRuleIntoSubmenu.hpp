/*
 * Copyright (C) 2010-2011 Daniel Richter <danielrichter2007@web.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef INC_Controller_Helper_RuleMover_Strategy_MoveRuleIntoSubmenu
#define INC_Controller_Helper_RuleMover_Strategy_MoveRuleIntoSubmenu

#include "../../../../Model/Rule.hpp"
#include "../../../../Model/ListCfg.hpp"
#include "../AbstractStrategy.hpp"
#include <memory>

class Controller_Helper_RuleMover_Strategy_MoveRuleIntoSubmenu :
	public Controller_Helper_RuleMover_AbstractStrategy,
	public Model_ListCfg_Connection
{
	public: void move(std::shared_ptr<Model_Rule> rule, Controller_Helper_RuleMover_AbstractStrategy::Direction direction)
	{
		auto proxy = this->grublistCfg->proxies.getProxyByRule(rule);
		auto& ruleList = proxy->getRuleList(proxy->getParentRule(rule));

		auto visibleRules = this->findVisibleRules(ruleList, rule);

		auto nextRule = this->getNextRule(visibleRules, rule, direction);

		if (nextRule == nullptr) {
			throw Controller_Helper_RuleMover_MoveFailedException("next rule not found", __FILE__, __LINE__);
		}

		if (nextRule->type != Model_Rule::SUBMENU) {
			throw Controller_Helper_RuleMover_MoveFailedException("next rule is not a submenu", __FILE__, __LINE__);
		}

		this->removeFromList(ruleList, rule);
		this->insertIntoSubmenu(nextRule, rule, direction);
	}

	private: void insertIntoSubmenu(
		std::shared_ptr<Model_Rule>& submenu,
		std::shared_ptr<Model_Rule> ruleToInsert,
		Controller_Helper_RuleMover_AbstractStrategy::Direction direction
	) {
		if (direction == Controller_Helper_RuleMover_AbstractStrategy::Direction::DOWN) {
			submenu->subRules.push_front(ruleToInsert);
		}

		if (direction == Controller_Helper_RuleMover_AbstractStrategy::Direction::UP) {
			submenu->subRules.push_back(ruleToInsert);
		}
	}
};
#endif
