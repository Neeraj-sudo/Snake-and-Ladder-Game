#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 

class snake_ladder
{
	private:
		map<int,int> snake;
		map<int,int> ladder;
		
		
	public:
		int pos;
		int board[100];
		void getdata();
		int throw_dice();
		int move_position(int pos);
		void print_result(int pos);
		bool is_snake(int pos);
		bool is_ladder(int pos);
		
};

int main()
{
	snake_ladder s;
	s.pos = 0;
	s.getdata();
	char t;
	
	while(s.board[s.pos]!=100)
	{
		cout<<"Press T to Throw Dice "<<"\n";
		cin>>t;
		if(t=='T' || t=='t')
		{
			//s.throw_dice();
			s.move_position(s.pos);
		}
		
	//	s.print_result();
	}
	cout<<"====================CONGRATS! GAME COMPLETE======================"<<"\n";
	return 0;
}

void snake_ladder::getdata()
{
	cout<<"welcome to SNAKE LADDER GAME!!"<<"\n";
	
	//cout<<"Preparing head and tails of each snake"<<"\n";
	snake.insert(pair<int, int>(90, 5)); 
    snake.insert(pair<int, int>(70, 12)); 
    snake.insert(pair<int, int>(50, 33)); 
    snake.insert(pair<int, int>(30, 24)); 
    
//	cout<<"Preparing head and tails of each ladder"<<"\n";
	ladder.insert(pair<int, int>(15, 44)); 
    ladder.insert(pair<int, int>(25, 55)); 
    ladder.insert(pair<int, int>(35, 65)); 
    ladder.insert(pair<int, int>(45, 85)); 
    
	for(int i=0;i<100;++i)
	board[i]=i+1;
	
	
	cout<<"You have Snakes at 90, 70, 50, 30 "<<"\n";
	cout<<"You have Ladders at 15, 25, 35, 45 "<<"\n";
	cout<<"...............LET'S START................'"<<"\n";
}

int snake_ladder:: throw_dice()  //to generate random number
{
	int upper=6, lower=1;
	int num = (rand() % (upper - lower + 1)) + lower; 
	cout<<"You Got "<<num <<"\n";
    return num;
}

int snake_ladder::move_position(int pos)
{
	board[pos]= board[pos] + throw_dice();
	cout<<"your new position is "<<board[pos]<<"\n";
	
	if(is_snake(board[pos]))
	{
		cout<<"OOPS....you got snake at "<<board[pos]<<"\n";
		pos = snake.at(board[pos]);
		print_result(pos);
	}
	if(is_ladder(board[pos]))
	{
		cout<<"WOW....you got ladder at "<<board[pos]<<"\n";
		pos = ladder.at(board[pos]);
		print_result(pos);
	}
	
}

void snake_ladder:: print_result(int pos)
{
	cout<<"your new position is "<<pos<<"\n";
}

bool snake_ladder:: is_snake(int pos)  // checking if position is snake
{
	map<int,int> :: iterator it;
	it = snake.find(pos); 
      
    if(it == snake.end()) 
        return false; 
    else
        {
        	pos = it->second;
        	return true;
		}
}

bool snake_ladder:: is_ladder(int pos)  //checking if position is a Ladder
{
	map<int,int> :: iterator it;
	it = ladder.find(pos); 
      
    if(it == ladder.end()) 
        return false; 
    else
        {
        	pos = it->second;
        	return true;
		}
}

