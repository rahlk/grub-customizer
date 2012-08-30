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

#include "../Model/Env.h"
#include "../View/Gtk/Main.h"
#include "../View/Gtk/About.h"
#include "../View/Gtk/Installer.h"
#include "../View/Gtk/Trash.h"
#include "../View/Gtk/EntryEditor.h"
#include "../View/Gtk/Settings.h"
#include "../View/Gtk/EnvEditor.h"
#include "../View/Gtk/Error.h"
#include "../lib/Mutex/GLib.h"
#include "../Controller/GLib/ThreadController.h"
#include "../lib/Logger/Stream.h"
#include <iostream>
#include "../lib/ContentParser/FactoryImpl.h"
#include "../lib/ContentParser/Linux.h"
#include "../lib/ContentParser/LinuxIso.h"
#include "../lib/ContentParser/Chainloader.h"
#include "../lib/ContentParser/Memtest.h"
#include "../Controller/EntryEditControllerImpl.h"
#include "../Controller/MainControllerImpl.h"
#include "../Controller/SettingsControllerImpl.h"
#include "../Controller/EnvEditorControllerImpl.h"
#include "../Controller/TrashControllerImpl.h"
#include "../Controller/InstallerControllerImpl.h"
#include "../Controller/AboutControllerImpl.h"
#include "../Controller/ControllerCollection.h"
#include "../Controller/ErrorControllerImpl.h"
#include "../Mapper/EntryNameImpl.h"
#include "../lib/assert.h"
#include "../lib/ArrayStructure.h"


int main(int argc, char** argv){
	if (getuid() != 0 && (argc == 1 || argv[1] != std::string("no-fork"))) {
		return system((std::string("pkexec ") + argv[0] + (argc == 2 ? std::string(" ") + argv[1] : "") + " no-fork").c_str());
	}
	setlocale( LC_ALL, "");
	bindtextdomain( "grub-customizer", LOCALEDIR);
	textdomain( "grub-customizer" );
	
	Logger_Stream logger(std::cout);

	try {
		Gtk::Main app(argc, argv);

		Glib::thread_init();

		Model_Env env;

		Model_ListCfg listcfg(env);
		View_Gtk_Main listCfgView;
		Model_SettingsManagerData settings(env);
		Model_SettingsManagerData settingsOnDisk(env);
		Model_Installer installer(env);
		View_Gtk_Installer installDlg;
		View_Gtk_Trash trashView;
		View_Gtk_EntryEditor entryEditDlg;
		Model_MountTable mountTable;
		Model_ListCfg savedListCfg(env);
		Model_FbResolutionsGetter fbResolutionsGetter;
		View_Gtk_Settings settingsDlg;
		Model_DeviceDataList deviceDataList;
		View_Gtk_About aboutDialog;
		Mutex_GLib listCfgMutex1;
		Mutex_GLib listCfgMutex2;
		ContentParser_FactoryImpl contentParserFactory;
		View_Gtk_EnvEditor envEditor;
		View_Gtk_Error errorView;
		Mapper_EntryNameImpl entryNameMapper;

		entryNameMapper.setView(listCfgView);

		entryEditDlg.setDeviceDataList(deviceDataList);
		envEditor.setDeviceDataList(deviceDataList);

		EntryEditControllerImpl entryEditController(env);
		entryEditController.setContentParserFactory(contentParserFactory);
		entryEditController.setView(entryEditDlg);
		entryEditController.setDeviceDataList(deviceDataList);
		entryEditController.setListCfg(listcfg);

		MainControllerImpl mainController(env);
		mainController.setListCfg(listcfg);
		mainController.setSettingsManager(settings);
		mainController.setSettingsBuffer(settingsOnDisk);
		mainController.setSavedListCfg(savedListCfg);
		mainController.setFbResolutionsGetter(fbResolutionsGetter);
		mainController.setDeviceDataList(deviceDataList);
		mainController.setMountTable(mountTable);
		mainController.setContentParserFactory(contentParserFactory);
		mainController.setView(listCfgView);
		mainController.setEntryNameMapper(entryNameMapper);

		SettingsControllerImpl settingsController(env);
		settingsController.setListCfg(listcfg);
		settingsController.setView(settingsDlg);
		settingsController.setSettingsManager(settings);
		settingsController.setSettingsBuffer(settingsOnDisk);
		settingsController.setFbResolutionsGetter(fbResolutionsGetter);

		EnvEditorControllerImpl envEditController(env);
		envEditController.setMountTable(mountTable);
		envEditController.setView(envEditor);

		TrashControllerImpl trashController(env);
		trashController.setEntryNameMapper(entryNameMapper);
		trashController.setListCfg(listcfg);
		trashController.setView(trashView);

		InstallerControllerImpl installController(env);
		installController.setInstaller(installer);
		installController.setView(installDlg);

		AboutControllerImpl aboutController(env);
		aboutController.setView(aboutDialog);

		ErrorControllerImpl errorController(env);
		errorController.setView(errorView);

		ControllerCollection controllerCollection;
		controllerCollection.entryEditController = &entryEditController;
		controllerCollection.mainController = &mainController;
		controllerCollection.settingsController = &settingsController;
		controllerCollection.envEditController = &envEditController;
		controllerCollection.trashController = &trashController;
		controllerCollection.installerController = &installController;
		controllerCollection.aboutController = &aboutController;
		controllerCollection.errorController = &errorController;

		entryEditController.setControllerCollection(controllerCollection);
		mainController.setControllerCollection(controllerCollection);
		settingsController.setControllerCollection(controllerCollection);
		envEditController.setControllerCollection(controllerCollection);
		trashController.setControllerCollection(controllerCollection);
		installController.setControllerCollection(controllerCollection);
		aboutController.setControllerCollection(controllerCollection);
		errorController.setControllerCollection(controllerCollection);

		GLib_ThreadController threadC(controllerCollection);
		mainController.setThreadController(threadC);
		settingsController.setThreadController(threadC);
		installController.setThreadController(threadC);
		errorController.setThreadController(threadC);


		listCfgView.putSettingsDialog(settingsDlg.getCommonSettingsPane(), settingsDlg.getAppearanceSettingsPane());

		//assign event listener
		listCfgView.setEventListener(mainController);
		installDlg.setEventListener(installController);
		trashView.setEventListener(trashController);
		entryEditDlg.setEventListener(entryEditController);
		settingsDlg.setEventListener(settingsController);
		listcfg.setEventListener(mainController);
		installer.setEventListener(installController);
		fbResolutionsGetter.setEventListener(settingsController);
		envEditor.setEventListener(envEditController);
		errorView.setEventListener(errorController);

		//assign logger
		listcfg.setLogger(logger);
		listCfgView.setLogger(logger);
		settings.setLogger(logger);
		settingsOnDisk.setLogger(logger);
		installer.setLogger(logger);
		installDlg.setLogger(logger);
		trashView.setLogger(logger);
		entryEditDlg.setLogger(logger);
		mountTable.setLogger(logger);
		savedListCfg.setLogger(logger);
		fbResolutionsGetter.setLogger(logger);
		settingsDlg.setLogger(logger);
		deviceDataList.setLogger(logger);
		aboutDialog.setLogger(logger);
		listCfgMutex1.setLogger(logger);
		listCfgMutex2.setLogger(logger);
		threadC.setLogger(logger);
		env.setLogger(logger);
		envEditor.setLogger(logger);
		mainController.setLogger(logger);
		entryEditController.setLogger(logger);
		settingsController.setLogger(logger);
		envEditController.setLogger(logger);
		trashController.setLogger(logger);
		errorController.setLogger(logger);
		installController.setLogger(logger);
		aboutController.setLogger(logger);

		// configure logger
		logger.setLogLevel(Logger_Stream::LOG_EVENT);
		if (argc > 1) {
			std::string logParam = argv[1];
			if (logParam == "debug") {
				logger.setLogLevel(Logger_Stream::LOG_DEBUG_ONLY);
			} else if (logParam == "log-important") {
				logger.setLogLevel(Logger_Stream::LOG_IMPORTANT);
			} else if (logParam == "quiet") {
				logger.setLogLevel(Logger_Stream::LOG_NOTHING);
			} else if (logParam == "verbose") {
				logger.setLogLevel(Logger_Stream::LOG_VERBOSE);
			}
		}

		//configure contentParser factory
		Model_DeviceMap deviceMap(env);
		ContentParser_Linux linuxParser(deviceMap);
		ContentParser_LinuxIso linuxIsoParser(deviceMap);
		ContentParser_Chainloader chainloadParser(deviceMap);
		ContentParser_Memtest memtestParser(deviceMap);

		contentParserFactory.registerParser(linuxParser, gettext("Linux"));
		contentParserFactory.registerParser(linuxIsoParser, gettext("Linux-ISO"));
		contentParserFactory.registerParser(chainloadParser, gettext("Chainloader"));
		contentParserFactory.registerParser(memtestParser, gettext("Memtest"));

		entryEditDlg.setAvailableEntryTypes(contentParserFactory.getNames());

		listcfg.setMutex(listCfgMutex1);
		savedListCfg.setMutex(listCfgMutex2);

		mainController.initAction();
		errorController.setApplicationStarted(true);
		app.run();
	} catch (Exception const& e) {
		logger.log(e, Logger::ERROR);
		return 1;
	}
}
