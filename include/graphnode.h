#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>

#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    // data handles (owned)
    std::vector<std::shared_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<std::weak_ptr<GraphEdge>> _parentEdges; // edges to preceding nodes 

    // proprietary members
    int _id;
    std::vector<std::string> _answers;
    ChatBot _chatBot;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }
    ChatBot *GetChatBotRef() { return &_chatBot; }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(std::weak_ptr<GraphEdge> edge);
    void AddEdgeToChildNode(std::shared_ptr<GraphEdge> edge);

    void MoveChatbotHere(ChatBot &&chatbot);
    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */