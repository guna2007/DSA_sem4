class Solution
{
public:
    int idx(char c)
    {
        if (c >= 'a' && c <= 'z')
            return c - 'a';
        return c - 'A' + 26;
    }

    string minWindow(string s, string t)
    {
        int m = s.length(), n = t.length();
        if (n > m)
            return "";

        int freqt[52] = {0};
        int window[52] = {0};

        for (char c : t)
            freqt[idx(c)]++;

        int have = 0, need = 0;
        for (int i = 0; i < 52; i++)
            if (freqt[i] > 0)
                need++;

        int bestLen = INT_MAX, bestL = -1;
        int l = 0;

        for (int r = 0; r < m; r++)
        {
            int idr = idx(s[r]);
            window[idr]++;
            if (window[idr] == freqt[idr])
                have++;

            while (have == need)
            {
                int len = r - l + 1;
                if (len < bestLen)
                {
                    bestLen = len;
                    bestL = l;
                }
                int idl = idx(s[l]);
                window[idl]--;
                if (window[idl] < freqt[idl])
                    have--;
                l++;
            }
        }

        return bestL == -1 ? "" : s.substr(bestL, bestLen);
    }
};
