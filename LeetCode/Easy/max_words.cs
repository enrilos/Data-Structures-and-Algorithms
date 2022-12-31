using System.Linq;

public class Solution
{
    /// <summary>
    /// Maximum Number of Words Found in Sentences
    /// </summary>
    public int MostWordsFound(string[] sentences)
        => sentences.Select(x => x.Split().Length).Max();
}