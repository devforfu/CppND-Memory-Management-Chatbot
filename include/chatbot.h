#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    std::unique_ptr<wxBitmap> _image; // avatar image

    // data handles (not owned)
    std::shared_ptr<GraphNode> _currentNode;
    std::shared_ptr<GraphNode> _rootNode;
    std::shared_ptr<ChatLogic> _chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode);
    void SetChatLogicHandle(ChatLogic *chatLogic);

    ChatLogic* GetChatLogicHandle();
    wxBitmap *GetImageHandle();

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif // CHATBOT_H_
