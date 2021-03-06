#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#define MSG_SIZE 1000
#define KEY_SIZE 100
#define ASCII_VALUE 96
#define MOD_VALUE 26

using namespace std;

class Cypher
{
	string message;
	string key;
	int msgLength, keyLength;

	
public :
	
	void ReadMessage()
	{
		cin.ignore();
		cout << "Enter the message." << endl;
		getline(cin, message);
		message.erase(remove(message.begin(), message.end(), ' '), message.end());
		msgLength = message.length();
	}

	void ReadKey()
	{
		cout << "Enter the key." << endl;
		getline(cin, key);
		keyLength = key.length();
	}

	void EncryptMessage()
	{
		int messageStream[MSG_SIZE], keyStream[KEY_SIZE], resultant[MSG_SIZE];

		for (int index = 0; index < msgLength; index++)
		{
			message[index] = tolower(message[index]);
			messageStream[index] = message[index] - ASCII_VALUE;
		}

		for (int index = 0; index < keyLength; index++)
		{
			key[index] = tolower(key[index]);
			keyStream[index] = key[index] - ASCII_VALUE;
		}

		for (int index = 0, aindex = 0; index < msgLength; index++, aindex++)
		{
			if (aindex == keyLength)
			{
				aindex = 0;
			}
			int temp = messageStream[index];
			resultant[index] = (temp > MOD_VALUE || temp < 1) ? messageStream[index] : ((keyStream[aindex] + messageStream[index]) % MOD_VALUE) + 1;
		}

		char result[MSG_SIZE];

		for (int index = 0; index < msgLength; index++)
		{
			result[index] = resultant[index] + ASCII_VALUE;
		}
		result[msgLength] = '\0';

		cout << "The Encrypted message is " << result << endl;
	}

	void DecryptMessage()
	{
		int messageStream[MSG_SIZE], keyStream[KEY_SIZE], resultant[MSG_SIZE];

		for (int index = 0; index < msgLength; index++)
		{
			messageStream[index] = message[index] - ASCII_VALUE;
		}

		for (int index = 0; index < keyLength; index++)
		{
			keyStream[index] = key[index] - ASCII_VALUE;
		}

		for (int index = 0, aindex = 0; index < msgLength; index++, aindex++)
		{
			if (aindex == keyLength)
			{
				aindex = 0;
			}
			int temp = messageStream[index];
			int value = ((messageStream[index] - keyStream[aindex]) % MOD_VALUE) - 1;
			resultant[index] = (temp > MOD_VALUE || temp < 1) ? messageStream[index] : (value < 0 ? (MOD_VALUE + value) : value);
		}

		char result[MSG_SIZE];

		for (int index = 0; index < msgLength; index++)
		{
			result[index] = (char)(resultant[index] + ASCII_VALUE);
		}
		result[msgLength] = '\0';

		cout << "The Decrypted message is " << result << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	char yesOrNo;
	bool isPlainText = true;
	cout << "Is message plain text? (Y/N)" << endl;
	cin >> yesOrNo;

	if (yesOrNo == 'y' || yesOrNo == 'Y')
		;
	else if (yesOrNo == 'n' || yesOrNo == 'N')
	{
		isPlainText = false;
	}

	Cypher cypher;

	try
	{
		if (isPlainText)
		{
			cypher.ReadMessage();
			cypher.ReadKey();
			cypher.EncryptMessage();
		}
		else
		{
			cypher.ReadMessage();
			cypher.ReadKey();
			cypher.DecryptMessage();
		}
	}
	catch (exception e)
	{
		throw e;
	}
	
	return 0;
}

