class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        map<int, int> freq;

        // count frequencies
        for (int card : hand) {
            freq[card]++;
        }

        // process smallest cards first
        for (auto it : freq) {

            int start = it.first;
            int count = it.second;

            // already used
            if (count == 0)
                continue;

            // create consecutive group
            for (int k = 0; k < groupSize; k++) {

                int card = start + k;

                // missing card
                if (freq[card] < count)
                    return false;

                freq[card] -= count;
            }
        }

        return true;
    }
};