class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, pair<int, int>> pool;
		for (char c : tasks)
		{
			if (pool.find(c) == pool.end())
			{
				pool[c] = pair<int, int>(0, -1);
			}
			pool[c].first += 1;
		}
		int jobnumber = tasks.size();
		int timestamp = 0;
		while (jobnumber)
		{
			auto iter = findJob(pool, timestamp, n);
			if (iter != pool.end())
			{
				iter->second.first -= 1;
				iter->second.second = timestamp;
				jobnumber--;
			}
			timestamp += 1;
		}
		return timestamp;
	}
private:
	unordered_map<char, pair<int, int>>::iterator findJob(unordered_map<char, pair<int, int>> &pool, int timestamp, int n)
	{
		unordered_map<char, pair<int, int>>::iterator ret = pool.end();
		for (auto iter = pool.begin(); iter != pool.end(); ++iter)
		{
			int &lastExecute = iter->second.second;
			if (iter->second.first > 0 &&(lastExecute == -1 || (timestamp - lastExecute - 1) >= n))
			{
				if (ret == pool.end() || ret->second.first < iter->second.first)
				{
					ret = iter;
				}
			}
		}
		return ret;
	}
};
