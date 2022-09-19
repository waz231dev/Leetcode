class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (auto path : paths) {
	    stringstream stream(path);
	    string location;
	    string str;
	    getline(stream, location, ' ');
	    while (getline(stream, str, ' ')) {
		    string name = location + '/' + str.substr(0, str.find('('));
		    string content = str.substr(str.find('(') + 1, str.find(')') - str.find('(') - 1);
		    mp[content].push_back(name);
	    }
    }

    for (auto file : mp) {
	    if (file.second.size() > 1)
		    ans.push_back(file.second);
    }

    return ans;
    }
};