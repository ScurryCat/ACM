#include <bits/stdc++.h>
using namespace std;

const int N = 11, M = 2009;
string winner;
int n, m;

struct PLAYER{
	string sf;
	int hp = 4;
	bool equip = 0;
	vector<int> dis;
	vector<char> handcard;
	set<int> enemy;
};
vector<PLAYER> player;
vector<char> cards;

inline bool gameover(){

}

/*
献殷勤：使用无懈可击挡下南猪入侵、万箭齐发、决斗；使用无懈可击抵消表敌意；
表敌意：对某个角色使用杀、决斗；使用无懈可击抵消献殷勤；
跳忠：即通过行动表示自己是忠猪。跳忠行动就是对主猪或对某只已经跳忠的猪献殷勤，或者对某只已经跳反的猪表敌意；
跳反：即通过行动表示自己是反猪。跳反行动就是对主猪或对某只已经跳忠的猪表敌意，或者对某只已经跳反的猪献殷勤。
注意：忠猪不会跳反，反猪也不会跳忠；不管是忠猪还是反猪，能够跳必然跳。

主猪：
主猪会认为「没有跳身份，且用南猪入侵 / 万箭齐发对自己造成伤害的猪」是类反猪（没伤害到不算，注意类反猪并没有表明身份），如果之后跳了，那么主猪会重新认识这只猪；
对于每种表敌意的方式，对逆时针方向能够执行到的第一只类反猪或者已跳反猪表；如果没有，那么就不表敌意；
决斗时会不遗余力弃置杀；
如果能对已经跳忠的猪或自己献殷勤，那么一定献；如果能够对已经跳反的猪表敌意，那么一定表。
忠猪：
对于每种表敌意的方式，对「逆时针方向能够执行到的第一只已经跳反的猪」表，如果没有，那么就不表敌意；
决斗时，如果对方是主猪，那么不会弃置杀，否则，会不遗余力弃置杀；
如果有机会对主猪或者已经跳忠的猪献殷勤，那么一定献。
反猪：
对于每种表敌意的方式，如果有机会则对主猪表，否则，对「逆时针方向能够执行到的第一只已经跳忠的猪」表，如果没有，那么就不表敌意；
决斗时会不遗余力弃置杀；
如果有机会对已经跳反的猪献殷勤，那么一定献。
*/

inline void updatedis(int id){
	for(int i=0; i<id; i++){
		for(int j=id+1; j<n; j++){
			player[i].dis[j]--;
		}
	}
	for(int i=0; i<n; i++) player[i].dis[id] = -1;
}

inline bool miss(int id){
	for(auto it=player[id].handcard.begin(); it<player[id].handcard.end(); ++it){
		char card = *it;
		if(card == 'D'){
			player[id].handcard.erase(it);
			return 1;
		}
	}
	return 0;
}

inline bool peach(int id){
	if(player[id].hp >= 4) return 0;
	player[id].hp++; return 1;
}

inline void damage(int id){
	--player[id].hp;
	while(player[id].hp <= 0){
		for(auto it=player[id].handcard.begin(); it<player[id].handcard.end(); it++){
			if(*it == 'P'){
				++player[id].hp;
				player[id].handcard.erase(it);
			}
			if(it == player[id].handcard.end() && player[id].hp <= 0){
				updatedis(id);
				return;
			}
		}
	}
}

inline void death(int p1, int p2){
	
}

inline bool attack(int p1, int p2){
	player[p2].enemy.insert(p1);
	if(miss(p2)) return 0;
	damage(p2);
	death(p1, p2);
	return 1;
}

inline bool kill(int id, bool diskill){
	if(diskill && !player[id].equip) return 0;
	for(int ne : player[id].enemy){
		if(player[id].dis[ne] == 1){
			attack(id, ne);
			return 1;
		}
	}
}

inline bool fight(int id){
	for(int ne : player[id].enemy){
		if(player[id].sf == "MP" && player[ne].sf == "ZP"){
			--player[ne].hp;
			return 1;
		}
		auto it1 = player[id].handcard.begin();
		auto it2 = player[ne].handcard.begin();
		int cur = 1;
		while(1){
			if(cur){
				while(it2 <= player[ne].handcard.end() && *it2 != 'K') ++it2;
				if(it2 == player[ne].handcard.end()){--player[ne].hp; break;}
				player[ne].handcard.erase(it2);
			}
			else{
				while(it1 <= player[id].handcard.end() && *it1 != 'K') ++it1;
				if(it1 == player[id].handcard.end()){--player[id].hp; break;}
				player[id].handcard.erase(it1);
			}
			cur ^= 1;
		}
		return 1;
	}
	return 0;
}

inline void nan(int id){
	for(int i = id+1; i < id+n; ++i){
		int cur = i % n;
	}
}

inline void wan(int id){

}

inline bool play(int id){
	bool diskill = 0;
	player[id].handcard.push_back(cards.back()); if(cards.size()>1) cards.pop_back();
	player[id].handcard.push_back(cards.back()); if(cards.size()>1) cards.pop_back();
	for(auto it=player[id].handcard.begin(); it < player[id].handcard.end(); ++it){
		char op = *it;
		switch(op){
			case 'P': if(peach(id)) player[id].handcard.erase(it); break;
			case 'K': if(kill(id, diskill)) player[id].handcard.erase(it), diskill = 1; break;
			case 'F': fight(id); break;
			case 'N': nan(id); break;
			case 'W': wan(id); break;
			case 'Z': player[id].equip = 1, player[id].handcard.erase(it); break;
		}
	}
	return gameover();
}

inline void solve(){
	cin >> n >> m;
	player.resize(n);
	cards.resize(m);
	for(int i=0; i<n; ++i){
		cin >> player[i].sf;
		for(int j=0; j<4; ++j){
			char ch; cin >> ch;
			player[i].handcard.push_back(ch);
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<i; ++j) player[i].dis.push_back(n-i+j);
		for(int j=i; j<n; ++j) player[i].dis.push_back(j-i);
	}

	for(int i=0; i<m; ++i) cin >> cards[i];
	reverse(cards.begin(), cards.end());
	for(int i=0; i<n; i = (i+1) % n){
		if(player[i].hp <= 0) continue;
		if(!play(i)) continue;
		break;
	}
	cout << winner << '\n';
	for()
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}