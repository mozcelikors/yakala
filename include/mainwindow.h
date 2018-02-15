/*
 * Copyright (c) 2018 Mustafa Ozcelikors
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v2.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v20.html
 *
 * Description:
 *     YAKALA project
 *
 * Author:
 *    M.Ozcelikors <mozcelikors@gmail.com>
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	void yakalaUiManipulations (void);

	void yakalaUpdateAliasTable (void);
	void yakalaUpdateNetworkTable (void);
	void yakalaUpdateEnvironmentTable (void);
	void yakalaUpdateProcessTable (void);
	void yakalaUpdateSocketsTable (void);

	void loadingAnimStart (void);
	void loadingAnimStop (void);

	~MainWindow();

protected:
	 bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::MainWindow *ui;
	int load_ctr;

signals:

private slots:
	void handleProcessTableClicked (int row, int col);
	void handleProcessKillButton();
	void handleSearchButton();
	void tabSelected();
	void timerSystemInfoUpdate(void);
	void handleAliasTableClicked (int row, int col);
	void handleEnvTableClicked (int row, int col);
	void handleAddAliasButtonClicked (void);
	void handleRemoveAliasButtonClicked (void);
	void handleNetworkComboBox (int idx);
	void handleNetworkSearchButton (void);
	void yakalaCloseEvent (void);
	void inputProcessChanged (void);

};

#endif // MAINWINDOW_H
