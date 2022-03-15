#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <stack>
#include <unordered_map>

#include <memory>
#include <string>

struct Variable
{
	std::string name;
	std::string type;
	Variable(std::string name, std::string type) : name(name), type(type) { }
};

static int blockCounter = 0;
struct Block
{
	int base;
	int uid;
	explicit Block(int base) : base(base), uid(++blockCounter) { }
};

struct VariableNode
{
	using Ptr = std::shared_ptr<VariableNode>;

	Variable* data;
	int blockId;
	Ptr previous;

	explicit VariableNode(Variable *data, int blockId)
		: data(data), blockId(blockId), previous(nullptr)
	{
	}

	VariableNode(Variable *data, int blockId, Ptr previous)
		: data(data), blockId(blockId), previous(previous)
	{
	}
};

static std::stack<Variable*> varStack; // active declared variables
static std::stack<Block> blockStack; // active block bases
static std::unordered_map<std::string, VariableNode::Ptr> varMap; // fast traversable declared variables

inline bool addVariable(std::string name, std::string type)
{
	auto end = varMap.end();
	int currentBlockId = blockStack.top().uid;

	auto iter = varMap.find(name);
	if (iter != end && iter->second->blockId == currentBlockId)
		return false; // multiple declarations in the same scope

	Variable *var = new Variable(name, type);
	varStack.push(var);

	if (iter != end)
		varMap[name] = std::make_shared<VariableNode>(var, currentBlockId, iter->second); // variable exists but in different scope
	else
		varMap[name] = std::make_shared<VariableNode>(var, currentBlockId); // brand new variable
	
	return true;
}

inline void removeVariables(int count = 1)
{
	while (count-- > 0)
	{
		Variable *var = varStack.top();
		VariableNode::Ptr node = varMap.at(var->name);

		if (node->previous != nullptr)
		{
			varMap[var->name] = node->previous; // restore previous declared variable
			node->previous.reset();
		}
		else
		{
			varMap.erase(var->name); // no previous declaration so erase it
		}

		node.reset();
		varStack.pop();
		delete var;
	}
}

inline std::string getVariableType(std::string name)
{
	auto iter = varMap.find(name);
	if (iter == varMap.end())
		return "UNDECLARED";
	return iter->second->data->type;
}

int main()
{
	int N; // number of input lines
	char icommand[8] = { 0 }; // a single command will be [1, 7] characters
	char iname[7] = { 0 }; // a single name will be [1, 6] characters
	char itype[7] = { 0 }; // a single type will be [1, 6] characters

	blockStack.push(Block(0)); // global scope

	scanf("%d", &N);
	while (N-- > 0)
	{
		if (scanf("%s", icommand) <= 0) continue;

		if (icommand[0] == '{')
		{
			blockStack.push(Block(varStack.size()));
		}
		else if (icommand[0] == '}')
		{
			int count = varStack.size() - blockStack.top().base; // number of variables in current block
			removeVariables(count); // remove variables local to current block
			blockStack.pop();
		}
		else if (strncmp(icommand, "DECLARE", sizeof(icommand)-1) == 0)
		{
			if (scanf("%s %s", iname, itype) <= 0) continue;
			bool success = addVariable(iname, itype); // add variable local to current block
			if (!success)
			{
				puts("MULTIPLE DECLARATION");
				break;
			}
		}
		else if (strncmp(icommand, "TYPEOF", sizeof(icommand)-1) == 0)
		{
			if (scanf("%s", iname) <= 0) continue;
			std::string type = getVariableType(iname);
			printf("%s\n", type.c_str());
		}
		else continue;
	}

	return 0;
}