// 15 - 30. ���� �˻� (p.369) (���� 2110��)

/*
	?�� �ڿ� ���� ���� �տ� ���� ��� ����� ����
	
	�տ� ���� ��� : ��� ���ڿ� ���� �� binary search �� �� �Ͽ� 
					 ���ǿ� �´� first idx�� last idx ã��

	�ڿ� ���� ��� : ��� ���ڿ��� �ش� ������ ����� �Ȱ��� �����ϱ�


	�ܾ�� : n (�ִ� 100000)
	������ : q (�ִ� 100000)
	���ڿ����� : l (�ִ� 10000)
	��� �� ��,

	�ܼ� sequential search�� ��� n*q*l
	sorting �� binary search�� �ϸ� n*logn + m *logn * l
	
	�� binary search�� �̵��� ������.
	
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
