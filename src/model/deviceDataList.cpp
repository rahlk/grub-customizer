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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "deviceDataList.h"

DeviceDataList::DeviceDataList(FILE* blkidOutput){
	loadData(blkidOutput);
}

DeviceDataList::DeviceDataList(){}

void DeviceDataList::loadData(FILE* blkidOutput){
	std::string deviceName, attributeName;
	bool inAttributeValue = false;
	bool deviceNameIsComplete = false, attributeNameIsComplete = false;
	int c;
	while ((c = fgetc(blkidOutput)) != EOF){
		if (inAttributeValue && c != '"'){
			(*this)[deviceName][attributeName] += c;
		}
		else {
			if (c == '\n'){
				deviceName = "";
				deviceNameIsComplete = false;
			}
			else if (c == ':'){
				deviceNameIsComplete = true;
			}
			else if (!deviceNameIsComplete) {
				deviceName += c;
			}
			else if (c != '=' && !attributeNameIsComplete) {
				if (c != ' ')
					attributeName += c;
			}
			else if (c == '=')
				attributeNameIsComplete = true;
			else if (c == '"'){
				if (inAttributeValue){
					attributeName = "";
					attributeNameIsComplete = false;
				}
				inAttributeValue = !inAttributeValue;
			}
		}
	}
}

void DeviceDataList::clear(){
	this->std::map<std::string, std::map<std::string, std::string> >::clear();
}
