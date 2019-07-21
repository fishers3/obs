#pragma once

#include "auth-oauth.hpp"

class MixerChat;

class MixerAuth : public OAuthStreamKey {
	Q_OBJECT

	QSharedPointer<MixerChat> chat;
	QSharedPointer<QAction> chatMenu;
	bool uiLoaded = false;

	std::string name;
	std::string id;

	bool RetryLogin() override;

	void SaveInternal() override;
	bool LoadInternal() override;

	bool GetChannelInfo(bool allow_retry = true);

	void LoadUI() override;

public:
	MixerAuth(const Def &d);

	static std::shared_ptr<Auth> Login(QWidget *parent);
};
