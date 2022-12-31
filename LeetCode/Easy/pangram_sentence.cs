public class Solution
{
    /// <summary>
    /// Check if the Sentence Is Pangram
    /// </summary>
    /// <param name="sentence"></param>
    /// <returns></returns>
    public bool CheckIfPangram(string sentence)
    {
        sentence = sentence.ToLower();
        var letters = new Dictionary<char, bool>();

        for (int i = 97; i <= 122; i++)
        {
            letters[(char)i] = false;
        }

        for (int i = 0; i < sentence.Length; i++)
        {
            if (letters.ContainsKey(sentence[i]) && !letters[sentence[i]])
            {
                letters[sentence[i]] = true;
            }
        }

        if (letters.Any(x => !x.Value))
        {
            return false;
        }

        return true;
    }
}