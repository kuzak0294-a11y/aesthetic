#pragma once

static float last_chat_spam_time = 0.0f;

void ChatSpammer() {
	if (!vars::misc::chat_spammer) return;
	if (!local_player) return;
	
	float current_time = Time::time();
	if (current_time - last_chat_spam_time < vars::misc::chat_spammer_delay) return;

	last_chat_spam_time = current_time;
}
