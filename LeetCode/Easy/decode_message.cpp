#include <iostream>
#include <string>
#include <cstring>
#include <map>

using std::string;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        std::map<char, char> map{{' ', ' '}};
        char result[message.size()];
        strcpy(result, message.c_str());
        map[' '] = ' ';
        int ascii = 97;

        for (int i = 0; i < key.size(); i++)
        {
            if (map.size() > 27)
            {
                break;
            }

            if (key[i] == ' ')
            {
                continue;
            }

            if (!map.contains(key[i]))
            {
                map[key[i]] = (char)ascii++;
            }
        }

        for (int i = 0; i < message.size(); i++)
        {
            result[i] = map[message[i]];
        }

        return string(result);
    }
};

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    Solution solution;
    std::cout << solution.decodeMessage(key, message) << std::endl;
    return 0;
}