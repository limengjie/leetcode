#ifndef __TWITTER__
#define __TWITTER__

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
	private:
		//struct Tweet {
			//int _id;
			//int _time;
			//Tweet(int id, int time): _id(id), _time(time) {}
		//};
		vector<int> Tweets;
		unordered_map<int, int> id_user;
		unordered_map<int, unordered_set<int>> user_followee;
		void new_user(int userId);
	public:
		Twitter();
		void postTweet(int userId, int TweetId);
		vector<int> getNewsFeed(int userId);
		void follow(int followerId, int followeeId);
		void unfollow(int followerId, int followeeId);
};

#endif

