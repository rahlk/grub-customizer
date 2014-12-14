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

#include <iostream>

#include "../Bootstrap/Regex.hpp"
#include "../Bootstrap/Thread.hpp"
#include "../Bootstrap/View.hpp"
#include "../Bootstrap/Application.hpp"
#include "../Bootstrap/Factory.hpp"
#include "../lib/ArrayStructure.hpp"
#include "../lib/ContentParser/Chainloader.hpp"
#include "../lib/ContentParser/FactoryImpl.hpp"
#include "../lib/ContentParser/Linux.hpp"
#include "../lib/ContentParser/LinuxIso.hpp"
#include "../lib/ContentParser/Memtest.hpp"
#include "../lib/Logger/Stream.hpp"
#include "../Mapper/EntryNameImpl.hpp"
#include "../Model/ThemeManager.hpp"
#include "../config.hpp"
#include "../Controller/AboutController.hpp"
#include "../Controller/EntryEditController.hpp"
#include "../Controller/EnvEditorController.hpp"
#include "../Controller/ErrorController.hpp"
#include "../Controller/InstallerController.hpp"
#include "../Controller/MainController.hpp"
#include "../Controller/SettingsController.hpp"
#include "../Controller/ThemeController.hpp"
#include "../Controller/TrashController.hpp"



int main(int argc, char** argv){
	if (getuid() != 0 && (argc == 1 || argv[1] != std::string("no-fork"))) {
		return system((std::string("pkexec ") + argv[0] + (argc == 2 ? std::string(" ") + argv[1] : "") + " no-fork").c_str());
	}
	setlocale( LC_ALL, "");
	bindtextdomain( "grub-customizer", LOCALEDIR);
	textdomain( "grub-customizer" );

	auto logger = std::make_shared<Logger_Stream>(std::cout);

	try {
		auto application          = std::make_shared<Bootstrap_Application>(argc, argv);
		auto view                 = std::make_shared<Bootstrap_View>();
		auto thread               = std::make_shared<Bootstrap_Thread>();
		auto regex                = std::make_shared<Bootstrap_Regex>();
		auto factory              = std::make_shared<Bootstrap_Factory>(application->applicationObject, logger);

		auto settingsOnDisk       = factory->create<Model_SettingsManagerData>();
		auto savedListCfg         = factory->create<Model_ListCfg>();

		factory->deviceMap->setRegexEngine(regex->engine);

		factory->entryNameMapper->setView(view->main);

		view->entryEditor->setDeviceDataList(factory->deviceDataList);
		view->envEditor->setDeviceDataList(factory->deviceDataList);

		auto entryEditController = factory->createController<EntryEditController>(view->entryEditor);
		auto mainController      = factory->createController<MainController>(view->main);
		auto settingsController  = factory->createController<SettingsController>(view->settings);
		auto envEditController   = factory->createController<EnvEditorController>(view->envEditor);
		auto trashController     = factory->createController<TrashController>(view->trash);
		auto installController   = factory->createController<InstallerController>(view->installer);
		auto aboutController     = factory->createController<AboutController>(view->about);
		auto errorController     = factory->createController<ErrorController>(view->error);
		auto themeController     = factory->createController<ThemeController>(view->theme);

		mainController->setSettingsBuffer(settingsOnDisk);
		mainController->setSavedListCfg(savedListCfg);

		mainController->setThreadHelper(thread->threadHelper);
		settingsController->setThreadHelper(thread->threadHelper);
		installController->setThreadHelper(thread->threadHelper);
		errorController->setThreadHelper(thread->threadHelper);
		entryEditController->setThreadHelper(thread->threadHelper);
		themeController->setThreadHelper(thread->threadHelper);

		//assign logger
		thread->mutex1->setLogger(logger);
		thread->mutex2->setLogger(logger);
		thread->threadHelper->setLogger(logger);

		// configure logger
		logger->setLogLevel(Logger_Stream::LOG_EVENT);
		if (argc > 1) {
			std::string logParam = argv[1];
			if (logParam == "debug") {
				logger->setLogLevel(Logger_Stream::LOG_DEBUG_ONLY);
			} else if (logParam == "log-important") {
				logger->setLogLevel(Logger_Stream::LOG_IMPORTANT);
			} else if (logParam == "quiet") {
				logger->setLogLevel(Logger_Stream::LOG_NOTHING);
			} else if (logParam == "verbose") {
				logger->setLogLevel(Logger_Stream::LOG_VERBOSE);
			}
		}

		//configure contentParser factory
		auto linuxParser = std::make_shared<ContentParser_Linux>();
		auto linuxIsoParser = std::make_shared<ContentParser_LinuxIso>();
		auto chainloadParser = std::make_shared<ContentParser_Chainloader>();
		auto memtestParser = std::make_shared<ContentParser_Memtest>();

		linuxParser->setDeviceMap(factory->deviceMap);
		linuxIsoParser->setDeviceMap(factory->deviceMap);
		chainloadParser->setDeviceMap(factory->deviceMap);
		memtestParser->setDeviceMap(factory->deviceMap);

		factory->contentParserFactory->registerParser(linuxParser, gettext("Linux"));
		factory->contentParserFactory->registerParser(linuxIsoParser, gettext("Linux-ISO"));
		factory->contentParserFactory->registerParser(chainloadParser, gettext("Chainloader"));
		factory->contentParserFactory->registerParser(memtestParser, gettext("Memtest"));

		linuxParser->setRegexEngine(regex->engine);
		linuxIsoParser->setRegexEngine(regex->engine);
		chainloadParser->setRegexEngine(regex->engine);
		memtestParser->setRegexEngine(regex->engine);

		view->entryEditor->setAvailableEntryTypes(factory->contentParserFactory->getNames());

		//set mutex
		factory->listcfg->setMutex(thread->mutex1);
		savedListCfg->setMutex(thread->mutex2);

		mainController->initAction();
		errorController->setApplicationStarted(true);

		application->applicationObject->run();
	} catch (Exception const& e) {
		logger->log(e, Logger::ERROR);
		return 1;
	}
}

