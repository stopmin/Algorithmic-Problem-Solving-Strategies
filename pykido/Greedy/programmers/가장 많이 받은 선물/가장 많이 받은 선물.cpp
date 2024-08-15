#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 더 많은 선물을 준 사람이 다음 달에 선물을 받는다. 
// 2. 선물 지수가 더 큰 사람이 다음 달에 선물을 받는다. 
// 3. 선물 지수, 주고받은 수가 같다면 주고 받지 않는다. 

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    // 0. 주고 받은 기록, 선물 지수 나타내기 
    int gift_history[50][50] = {0, };
    int gift_exp[50] = {0, };

    // 1. 주고 받은 선물과 선물 지수 정리하기 
    for (int i = 0; i < gifts.size(); ++i) {
        string cur_gift = gifts[i];
        int blankIndex = cur_gift.find(' ');
        string giver = cur_gift.substr(0, blankIndex);
        string receiver = cur_gift.substr(blankIndex + 1);

        int giverIndex = find(friends.begin(), friends.end(), giver) - friends.begin();
        int receiverIndex = find(friends.begin(), friends.end(), receiver) - friends.begin();

        // 선물 주고 받은 기록 저장하기
        gift_history[giverIndex][receiverIndex]++;

        // 선물 지수 기록하기
        gift_exp[giverIndex]++;
        gift_exp[receiverIndex]--;
    }

    // 2. 예측하기 (받는 경우만 생각하기)
    int friends_num = friends.size();
    int next_month[50] = {0, };
    for (int i = 0; i < friends.size(); ++i) {
        for (int j = 0; j < friends.size(); ++j) {
            if (i == j) continue;

            // (1) 선물을 주고 받음 
            if (gift_history[i][j] || gift_history[j][i]) {
                if (gift_history[i][j] > gift_history[j][i]) {
                    next_month[i]++;
                } else if ((gift_history[i][j] == gift_history[j][i]) && (gift_exp[i] > gift_exp[j])) {
                    next_month[i]++;
                }
            } else {
                // (2) 선물을 주고 받지 않음
                if (gift_exp[i] > gift_exp[j]) {
                    next_month[i]++;
                }
            }
        }
        answer = max(answer, next_month[i]);
    }

    return answer;
}