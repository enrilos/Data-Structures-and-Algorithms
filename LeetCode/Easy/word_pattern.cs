using System;
using System.Linq;
using System.Collections.Generic;

public class Solution
{
    public bool WordPattern(string pattern, string str)
    {
        var words = str.Split();

        if (pattern.Length != words.Length)
        {
            return false;
        }

        var minLength = Math.Min(words.Length, pattern.Length);
        var map = new Dictionary<string, string>();

        for (int i = 0; i < minLength; i++)
        {
            var patternString = pattern[i].ToString();

            if (!map.ContainsKey(patternString))
            {
                if (map.Values.Contains(words[i]))
                {
                    return false;
                }

                map[patternString] = words[i];
            }
            else if (map[patternString] != words[i])
            {
                return false;
            }
        }

        return true;
    }
}