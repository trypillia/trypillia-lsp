#pragma once

#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include <nlohmann/json.hpp>
#include "native_docs.h"
#include <iostream>
#include <string>
#include <unordered_map>

using json = nlohmann::json;

namespace trypillia {

class LSPServer {
  public:
    LSPServer() = default;
    void run();

  private:
    void handleMessage(const json &message);
    void handleInitialize(const json &message);
    void handleInitialized(const json &message);
    void handleDidOpen(const json &message);
    void handleDidChange(const json &message);
    void handleHover(const json &message);
    void handleDefinition(const json &message);
    void handleCompletion(const json &message);
    void handleSignatureHelp(const json &message);
    void handleSemanticTokens(const json &message);

    void publishDiagnostics(const std::string &uri, const std::string &text);

    void sendMessage(const json &message);
    std::string readMessage();

    bool isRunning = true;
    std::unordered_map<std::string, std::string> documents;
    json nativeDocs;
};

} // namespace trypillia
