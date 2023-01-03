public class Solution
{
    // Distant Barcodes
    // Difficulty: Medium
    public int[] RearrangeBarcodes(int[] barcodes)
    {
        var map = new Dictionary<int, int>();

        for (int i = 0; i < barcodes.Length; i++)
        {
            if (!map.ContainsKey(barcodes[i]))
            {
                map[barcodes[i]] = 0;
            }
            map[barcodes[i]]++;
        }

        map = map.OrderByDescending(x => x.Value).ToDictionary(x => x.Key, y => y.Value);

        var index = 0;
        var result = new int[barcodes.Length];

        foreach (var numOccurences in map)
        {
            var key = numOccurences.Key;

            while (map[key] > 0)
            {
                result[index] = key;
                map[key]--;
                index += 2;
                if (index >= barcodes.Length) index = 1;
            }
        }

        return result;
    }
}