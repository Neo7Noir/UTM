import telebot

bot = telebot.TeleBot("5279447839:AAEW5Nrm5p9cq-PxBMxyQYGjbQJmKmr4HV0", parse_mode=None)
@bot.message_handler(content_types=['text'])
def send_echo(message):
	#bot.reply_to(message, message.text)
    bot.send_message(message.chat.id, message.text)

bot.polling(none_stop=True)