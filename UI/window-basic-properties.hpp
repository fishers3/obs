/******************************************************************************
    Copyright (C) 2014 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include <QDialog>
#include <QDialogButtonBox>
#include <QPointer>
#include <QSplitter>
#include "qt-display.hpp"
#include <obs.hpp>

class OBSPropertiesView;
class OBSBasic;

#include "ui_OBSBasicProperties.h"

class OBSBasicProperties : public QDialog {
	Q_OBJECT

private:
	OBSBasic *main;

	std::unique_ptr<Ui::OBSBasicProperties> ui;
	bool acceptClicked;

	OBSSource origSource;
	OBSSourceAutoRelease source;
	OBSSignal removedSignal;
	OBSSignal renamedSignal;
	OBSSignal updatePropertiesSignal;
	OBSData oldSettings;
	OBSPropertiesView *view;
	QDialogButtonBox *buttonBox;
	QSplitter *windowSplitter;

	OBSSourceAutoRelease sourceA;
	OBSSourceAutoRelease sourceB;
	OBSSourceAutoRelease sourceClone;
	bool direction = true;
	bool isDefaults = false;

	static void SourceRemoved(void *data, calldata_t *params);
	static void SourceRenamed(void *data, calldata_t *params);
	static void UpdateProperties(void *data, calldata_t *params);
	static void DrawPreview(void *data, uint32_t cx, uint32_t cy);
	static void DrawTransitionPreview(void *data, uint32_t cx, uint32_t cy);
	void UpdateCallback(void *obj, obs_data_t *settings);
	bool ConfirmQuit();
	int CheckSettings();
	void Cleanup();
	void UpdateOriginalSource(bool reject = false);

private slots:
	void on_buttonBox_clicked(QAbstractButton *button);
	void AddPreviewButton();
	void EnableApplyButton(bool enable = true);

public:
	OBSBasicProperties(QWidget *parent, OBSSource source_);
	~OBSBasicProperties();

	void Init();

protected:
	virtual void closeEvent(QCloseEvent *event) override;
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
	virtual bool nativeEvent(const QByteArray &eventType, void *message,
				 qintptr *result) override;
#else
	virtual bool nativeEvent(const QByteArray &eventType, void *message,
				 long *result) override;
#endif
	virtual void reject() override;
};
