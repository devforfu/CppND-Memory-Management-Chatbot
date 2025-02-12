#include <memory>
#include "chatlogic.h"
#include "graphedge.h"
#include "graphnode.h"
#include "utils.h"

GraphNode::GraphNode(int id)
{
    LOG("creating a graph node with ID =", id);
    _id = id;
}

GraphNode::~GraphNode()
{
    LOG("dropping graph node with ID =", _id);
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(std::weak_ptr<GraphEdge> edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::shared_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge);
}

void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    LOG("chat bot enters node with ID =", _id);
    _chatBot = chatbot;
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    LOG("chat bot leaves node with ID =", _id, " and comes to ID =", newNode->GetID());
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    return _childEdges[index].get();
}