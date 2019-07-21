#pragma once

#include "auth-oauth.hpp"

class RestreamWidget;

class RestreamAuth : public OAuthStreamKey {
	Q_OBJECT

	QSharedPointer<RestreamWidget> chat;
	QSharedPointer<RestreamWidget> info;
	QSharedPointer<QAction> chatMenu;
	QSharedPointer<QAction> infoMenu;
	bool uiLoaded = false;

	bool RetryLogin() override;

	void SaveInternal() override;
	bool LoadInternal() override;

	bool GetChannelInfo();

	void LoadUI() override;

public:
	RestreamAuth(const Def &d);

	static std::shared_ptr<Auth> Login(QWidget *parent);
};
