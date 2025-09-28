#include <Geode/modify/FLAlertLayer.hpp>
#include <Geode/Geode.hpp>
#include <Geode/fmod/fmod.hpp>
#include <regex>

using namespace geode::prelude;

class $modify(GDPopupSoundsHook,FLAlertLayer) {
    bool init(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale) {
        if (!FLAlertLayer::init(delegate, title, desc, btn1, btn2, width, scroll, height, textScale)) return false;
        
        const std::string fullText = title + " " + std::string(desc);

        std::regex error_pattern("- \\d+");

        if (std::regex_search(fullText, error_pattern)) {
            FMODAudioEngine::sharedEngine()->playEffect("/rescources/GJ_Error.ogg"_spr);
        } else {
            FMODAudioEngine::sharedEngine()->playEffect("/resources/GJ_Popup.ogg"_spr);
        }

        return true;
    }
};
