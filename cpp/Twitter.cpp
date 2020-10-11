#include <iostream>
#include "Twitter.h"

using namespace std;

Twitter::Twitter() {
	cout << "new obj\n";
}

void Twitter::new_user(int userId) {
		user_followee[userId] = unordered_set<int>();
}

void Twitter::postTweet(int userId, int TweetId) {
	//if this is the 1st time 
	//this usr appears 
	if (user_followee.find(userId) == user_followee.end()) {
		new_user(userId);
	}
	
	//save tweet
	id_user[TweetId] = userId;
	Tweets.push_back(TweetId);
}

vector<int> Twitter::getNewsFeed(int userId) {
	vector<int> news;
	if (user_followee.find(userId) == user_followee.end()) 
		return news;

	//put all followee together
	unordered_set<int> all_followees;
	all_followees.insert(userId);
	for (auto it = user_followee[userId].begin(); it != user_followee[userId].end(); ++it) {
		all_followees.insert(*it);
	}

	//for (auto it = all_followees.begin(); 
			//it != all_followees.end();
			//++it)
		//cout << *it << " ";
	//cout << endl;

	//traverse and get tweets
	auto rit = Tweets.rbegin();
	int i = 0;
	for ( ; rit != Tweets.rend() && i < 10; ++i, ++rit) {
		int user = id_user[*rit];
		auto it = all_followees.find(user);
		if (it != all_followees.end())
				news.push_back(*rit);
	}

	//print news
	cout << "news:\n";
	for (size_t i = 0; i < news.size(); ++i) 
		cout << news[i] << " ";
	cout << endl;

	return news;
}

void Twitter::follow(int followerId, int followeeId) {
	if (user_followee.find(followerId) == user_followee.end()) {
		new_user(followerId);
	}
	
	if (user_followee.find(followeeId) == user_followee.end()) {
		new_user(followeeId);
	}

	user_followee[followerId].insert(followeeId);
}


void Twitter::unfollow(int followerId, int followeeId) {
	bool userNotExist = false;
	if (user_followee.find(followeeId) == user_followee.end()) {
		new_user(followeeId);
		userNotExist = true;
	}

	if (user_followee.find(followerId) == user_followee.end()) {
		new_user(followerId);
		userNotExist = true;
	}

	if (userNotExist)
		return;

	auto it = user_followee[followerId].find(followeeId);
	if (it != user_followee[followerId].end())
		user_followee[followerId].erase(it);
}

int main() {
	Twitter twitter = Twitter();

	twitter.postTweet(1, 5);

	twitter.getNewsFeed(1);

	twitter.follow(1, 2);

	twitter.postTweet(2, 6);

	twitter.getNewsFeed(1);

	twitter.unfollow(1, 2);

	twitter.getNewsFeed(1);


	return 0;
}
