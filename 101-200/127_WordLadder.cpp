//Description
//Given two words(beginWord and endWord), 
//and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.

//Solution :
//Solution 1:
//use the idea of BFS:we change the beginWord into the word int wordList that are different of one character
//until the beginWord=endWord,TLX

//Solution 2:
//use the matrix under the graph-theoretic,but TLX

//Solution 3:
//also use BFS ,but do an improvement
//1).add all the neightouring elements of *word and delete them from set *toVisit at one time
//loop the *toVisit,if the element equal endWord,return setp
//else let the 1) function agagin
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//Solution 1:

		/*wordList.push_back(beginWord);
		unordered_set<string> wordListSet;
		for (auto v : wordList) wordListSet.insert(v);
		queue<string> toVisit;

		this->find_answer(beginWord, wordListSet, toVisit);
		int step = 2;
		while (!toVisit.empty()){
			int num = toVisit.size();
			for (int i = 0; i < num;i++) {
				string now = toVisit.front();
				toVisit.pop();
				if (now == endWord) return step;
				this->find_answer(now, wordListSet, toVisit);
			}
			step++;
		}
		return 0;*/

		//Solution 2:
		unordered_set<string> wordListSet;
		wordListSet.insert(beginWord);
		for (auto v : wordList) wordListSet.insert(v);

		unordered_set<string> head, tail, *phead, *ptail;
		head.insert(beginWord);
		tail.insert(endWord);

		int answer = 2;
		while (!head.empty()&&!tail.empty()){
			if (head.size() < tail.size()) {
				phead = &head; ptail = &tail;
			}
			else {
				phead = &tail; ptail = &head;
			}

			unordered_set<string> temp;
			for (auto p = phead->begin(); p != phead->end();p++) {
				string word = *p;
				wordListSet.erase(word);
				for (int length = 0; length < word.size();length++) {
					char backup = word[length];
					for (int character = 0; character < 26;character++) {
						word[length] = 'a' + character;
						if (ptail->find(word) != ptail->end())
							return answer;
						if (wordListSet.find(word) != wordListSet.end()) {
							wordListSet.erase(word);
							temp.insert(word);
						}
					}
					word[length] = backup;
				}
			}
			answer++;
			swap(*phead, temp);

		}
		return 0;
	}

private:
	void find_answer(string beginWord, unordered_set<string> &wordList,queue<string>& toVisit) {
		wordList.erase(beginWord);
		for (int i = 0; i < beginWord.size();i++) {
			char backup = beginWord[i];
			for (int j = 0; j < 26;j++) {
				char now = 'a' + j;
				beginWord[i] = now;
				if (wordList.find(beginWord) != wordList.end()) {
					wordList.erase(beginWord);
					toVisit.push(beginWord);
				}
			}
			beginWord[i] = backup;
		}
	}

};
