#include<bits/stdc++.h>

using namespace std ; 

class Board{
    public:
        int size ; 
        unordered_map<int,int>snakes ; 
        unordered_map<int,int>ladders ; 

        Board(int size) : size(size) {} 

        void addSnake(int head , int tail){
            snakes[head] = tail ; 
        }

        void addLadder(int start , int end){
            ladders[start] = end ; 
        }

        int getFinalPosition(int position){
            while(snakes.count(position) || ladders.count(position)){
                if(snakes.count(position)){
                    position = snakes[position] ; 
                }
                else if(ladders.count(position)){
                    position = ladders[position] ;
                }
            }

            return position ; 
        }
};

class Player{
    public : 
        string name ; 
        int position ; 


        Player(string name) : name(name) , position(0) {} 

        void move(int diceValue , Board & board){
            int newPosition = position + diceValue ; 

            if(newPosition <= board.size){
                position = board.getFinalPosition(newPosition) ; 
            }
        }
};

class Game{
    private:
        Board board; 
        queue<Player>players ; 

    public:
        Game(int boardSize) : board(boardSize){
            srand(time(0)) ; 
        }

        void addPlayer(string name){
            players.push(Player(name)) ; 
        }

        void addSnake(int head , int tail){
            board.addSnake(head , tail) ; 
        }

        void addLadder(int start , int end){
            board.addLadder(start , end) ; 
        }

        int rollDice(){
            return rand()%6 + 1; 
        }

        void play(){
            while(true){
                Player currentPlayer = players.front() ; 
                players.pop() ; 

                int diceValue = rollDice() ; 
                int initialPosition = currentPlayer.position ; 

                currentPlayer.move(diceValue , board) ; 

                cout << currentPlayer.name << " rolled a " << diceValue << " and move from " << initialPosition << " to " << currentPlayer.position << endl; 

                if(currentPlayer.position == board.size){
                    cout << currentPlayer.name << " wins the game !" << endl; 
                    break ; 
                }

                players.push(currentPlayer) ; 
            }
        }


};






int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int SnakeCount ,  LadderCount , PlayerCount ;
    cin >> SnakeCount  ; 

    Game game(100) ;  // Board size of 100 ; 

    // input snakes ; 
    for(int i = 0 ; i< SnakeCount ; i++){
        int head , tail ; 
        cin >> head >> tail ; 
        game.addSnake(head , tail) ; 
    }
    
    // input ladders ; 
    cin >> LadderCount ; 
    for (int i = 0; i < LadderCount; ++i) {
        int start, end;
        cin >> start >> end;
        game.addLadder(start, end);
    }

    // Input players ; 
    cin >> PlayerCount ; 

    for(int i = 0 ; i< PlayerCount ; i++){
        string name ; 
        cin >> name ; 
        game.addPlayer(name) ; 

    }


    // Game start
    game.play() ; 

    return 0 ; 





}