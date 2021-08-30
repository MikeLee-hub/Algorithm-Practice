// 15 - 30. 가사 검색 (p.369) (백준 2110번)

/*
	?가 뒤에 오는 경우와 앞에 오는 경우 나누어서 생각
	
	앞에 오는 경우 : 모든 문자열 정렬 후 binary search 두 번 하여 
					 조건에 맞는 first idx와 last idx 찾기

	뒤에 오는 경우 : 모든 문자열과 해당 쿼리를 뒤집어서 똑같이 생각하기


	단어수 : n (최대 100000)
	쿼리수 : q (최대 100000)
	문자열길이 : l (최대 10000)
	라고 할 때,

	단순 sequential search일 경우 n*q*l
	sorting 후 binary search를 하면 n*logn + m *logn * l
	
	로 binary search가 이득을 가진다.
	
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> divided_words[10005];
vector<string> reverse_word[10005];
string target;

string replaceAll(string str, string from, string to) {
	string res = str;
	int pos = 0;
	while ((pos = res.find(from, pos)) != string::npos)
	{
		res.replace(pos, from.size(), to);
		pos += to.size();
	}
	return res;
}

int get_len() {
	vector<string>::iterator first;
	vector<string>::iterator last;
	int tmp = target.length();
	if (target[0] == '?') {
		reverse(target.begin(), target.end());
		first = upper_bound(reverse_word[tmp].begin(), reverse_word[tmp].end(), replaceAll(target, "?", "a"));
		last = lower_bound(reverse_word[tmp].begin(), reverse_word[tmp].end(), replaceAll(target, "?", "z"));
	}
	else {
		first = upper_bound(divided_words[tmp].begin(), divided_words[tmp].end(), replaceAll(target, "?", "a"));
		last = lower_bound(divided_words[tmp].begin(), divided_words[tmp].end(), replaceAll(target, "?", "z"));
	}
	return last - first;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	int i;
	int tmp;
	int q = queries.size();
	int w = words.size();

	for (i = 0; i < w; i++) {
		tmp = words[i].length();
		divided_words[tmp].push_back(words[i]);
		reverse(words[i].begin(), words[i].end());
		reverse_word[tmp].push_back(words[i]);
	}

	for (i = 0; i < 10001; i++) {
		sort(divided_words[i].begin(), divided_words[i].end());
		sort(reverse_word[i].begin(), reverse_word[i].end());
	}

	for (i = 0; i < q; i++) {
		target = queries[i];
		answer.push_back(get_len());
	}

	return answer;
}

int main() {
	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao"};
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	solution(words, queries);
	//cout << solution(words, queries);
	return 0;
}
