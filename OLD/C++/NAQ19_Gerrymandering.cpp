#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

struct DistrictResults
{
    int district;
    int votesA;
    int votesB;
};

void includeResults(std::map<int, DistrictResults> &electionResults, DistrictResults &districtResults)
{
    auto iter = electionResults.find(districtResults.district);
    if (iter == electionResults.end())
    {
        electionResults.emplace(districtResults.district, districtResults);
    }
    else
    {
        DistrictResults &current = iter->second;
        current.votesA += districtResults.votesA;
        current.votesB += districtResults.votesB;
    }
}

int main() {
    int precincts, districts;
    std::cin >> precincts;
    std::cin >> districts;

    std::map<int, DistrictResults> electionResults;
    for (int i = 0; i < precincts; i++)
    {
        int district, votesA, votesB;
        std::cin >> district;
        std::cin >> votesA;
        std::cin >> votesB;
        DistrictResults results = {
                district,
                votesA,
                votesB
        };
        includeResults(electionResults, results);
    }

    int totalVotes = 0;
    int totalWastedVotesA = 0;
    int totalWastedVotesB = 0;
    for (auto result : electionResults)
    {
        DistrictResults results = result.second;

        //Print winner
        bool didAWin = results.votesA > results.votesB;
        if (didAWin)
            std::cout << "A ";
        else
            std::cout << "B ";

        //Print wasted votes
        int wastedVotesA, wastedVotesB;
        if (didAWin)
        {
            wastedVotesA = results.votesA - (((results.votesA+results.votesB) / 2) + 1);
            wastedVotesB = results.votesB;
        }
        else
        {
            wastedVotesB = results.votesB - (((results.votesA+results.votesB) / 2) + 1);
            wastedVotesA = results.votesA;
        }
        std::cout << wastedVotesA << " " << wastedVotesB << "\n";

        totalVotes += results.votesA + results.votesB;
        totalWastedVotesA += wastedVotesA;
        totalWastedVotesB += wastedVotesB;
    }

    double efficiencyGap = (double)abs(totalWastedVotesA - totalWastedVotesB) / double(totalVotes);
    std::cout << std::setprecision(10) << efficiencyGap;
    return 0;
}