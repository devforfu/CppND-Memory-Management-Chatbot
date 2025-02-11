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
    GraphNode* _currentNode;
    GraphNode* _rootNode;
    ChatLogic* _chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    ChatBot();
    ChatBot(std::string filename);
    ~ChatBot();

    ChatBot(ChatBot const &other);
    ChatBot(ChatBot &&other);
    ChatBot &operator=(ChatBot const &other);
    ChatBot &operator=(ChatBot &&other);

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }

    GraphNode* GetCurrentNode() const { return _currentNode; }
    ChatLogic* GetChatLogicHandle() const { return _chatLogic; };
    GraphNode* GetRootNode() const { return _rootNode; }
    wxBitmap *GetImageHandle() const { return _image.get(); }
    std::unique_ptr<wxBitmap> TakeImage()  { return std::move(_image); }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif // CHATBOT_H_
