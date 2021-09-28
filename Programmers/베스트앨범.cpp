#include <string>
#include <vector>
#include <algorithm> 
#include <map>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first > b.first; // 재생횟수 내림차순  
}

bool compare_song_cnt(pair<string,int> a, pair<string,int> b){
    return a.second > b.second; // 노래 개수 내림차순  
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> genre_cnt;
    map<string, vector<pair<int,int>> > genre_playlist; 
    vector<pair<string, int>> genre_v;  

    for(int i = 0; i < genres.size(); i++){
        genre_cnt[genres[i]] += plays[i]; // 장르별 재생횟수 누적
        genre_playlist[genres[i]].push_back({plays[i], i}); // 장르별 노래의 재생횟수 및 고유번호 
    } 

    for( auto &song : genre_playlist){
        sort(song.second.begin(), song.second.end(), compare);    
    }    

    genre_v.assign(genre_cnt.begin(), genre_cnt.end()); // 장르별 노래 개수
    sort(genre_v.begin(), genre_v.end(), compare_song_cnt); // 내림차순  

    for(int i = 0; i <genre_v.size(); i++){ 
        string genre_name = genre_v[i].first; 
        for(int j = 0; ( j <genre_playlist[genre_name].size() && j < 2 ); j++){ 
            answer.push_back(genre_playlist[genre_name][j].second);
        } 
    }

    return answer;
}
