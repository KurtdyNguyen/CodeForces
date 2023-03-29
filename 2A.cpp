#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

typedef struct Round{
    std::string name;
    int point;
} Round;

//round constructor, set name and point for that round
Round setter(std::string name, int point){
    Round round = {name, point};
    return round;
}

std::string maxPoint(std::vector<Round> total, std::vector<Round> base)
{
    Round max = *total.begin();
    std::vector<std::string> max_contender; //all possible winner with max points
    //iterate through the vector and update max value
    for (auto i = total.begin() + 1; i != total.end(); i++)
    {
        if (max.point < i->point)
        {
            max = *i;
        }
    }

    max_contender.push_back(max.name);
    //check for dupes of max
    bool dupe = false;
    for (auto i = total.begin(); i != total.end(); i++)
    {
        if (max.point == i->point && max.name != i->name)
        {
            max_contender.push_back(i->name);
            dupe = true;
        }
    }
    //if there is no dupe, immediately return winner
    if (!dupe)
        return max.name;
    //check who get to max point earliest
    //simulate the rounds again, this time with only the possible winners
    //check their points every round
    std::vector<Round> sim_round;
    for (auto i = max_contender.begin(); i != max_contender.end(); i++)
    {
        sim_round.push_back(setter(*i, 0)); //possible winners with 0 pts at the beginning
    }
    for (auto i = base.begin(); i != base.end(); i++)
    {
        if (std::find(max_contender.begin(), max_contender.end(), i->name) == max_contender.end())//check if possible winners play this round
            continue;
        for (auto j = sim_round.begin(); j != sim_round.end(); j++)
        {
            if (j->name != i->name)
                continue;
            j->point += i->point;
            //if contestant's point this round is equal or more than max point, immediately return contestant's name
            if (j->point >= max.point)
                return j->name;   
        }
    }
    return max.name;
}

int main(){
    std::vector<Round> round, total;
    std::vector<std::string> unique_name;
    std::vector<std::string>::iterator istr;
    std::string i_name;
    int testcase, i_point;
    std::cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        std::cin >> i_name >> i_point;
        round.push_back(setter(i_name, i_point));
        unique_name.push_back(i_name); //get name to another vector
    }
    //sort name and leave only unique name, remove duplications
    std::sort(unique_name.begin(), unique_name.end());
    istr = std::unique(unique_name.begin(), unique_name.end());
    
    unique_name.resize(std::distance(unique_name.begin(), istr)); //resize the name vector to its real size
    
    //initialize the scoreboard
    for (auto i = unique_name.begin(); i != unique_name.end(); i++)
    {
        total.push_back(setter(*i, 0));
    }
    //iterate through rounds and add points
    for (auto i = round.begin(); i != round.end(); i++)
    {
        for (auto j = total.begin(); j != total.end(); j++)
        {
            if (i->name == j->name)
            {
                j->point += i->point;//add round's point to total point
                break;
            }
        }    
    }
    std::cout << maxPoint(total, round);
    return 0;
}
