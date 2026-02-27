class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string msg = "";
        for (auto &s : strs)
        {
            int len = s.length();
            msg += to_string(len);
            msg += '#';
            msg += s;
        }
        return msg;
    }

    vector<string> decode(string msg)
    {
        vector<string> res;
        int i = 0;

        while (i < msg.size())
        {
            int len = 0;

            // parse length manually
            while (msg[i] != '#')
            {
                len = len * 10 + (msg[i] - '0');
                i++;
            }

            i++; // skip '#'

            res.push_back(msg.substr(i, len));
            i += len;
        }

        return res;
    }
};
