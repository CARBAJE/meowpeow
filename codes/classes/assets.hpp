#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <string>
#include <raylib.h>
#include <map>

#include "texture_details.hpp"

class Assets {
    private:
        static std::map<std::string, TextureDetails> mTextures;
    public:
        static TextureDetails GetTexture (const std::string& name) {
            //no error checking
            return mTextures[name];
        }

        static void LoadAssetTexture (const std::string& path, const std::string& name) {
            TextureDetails result;
            Rectangle source = {};

            if (mTextures.find(path) != mTextures.end()) {
                result.texture = mTextures[path].texture;
                source.x = 0;
                source.y = 0;
                source.width = result.texture.width;
                source.height = result.texture.height;
            }
            else {
                Texture2D texture = LoadTexture(path.c_str());

                result.texture = texture;

                source.x = 0;
                source.y = 0;
                source.width = result.texture.width;
                source.height = result.texture.height;

                TextureDetails canched = {result.texture, source };
                mTextures[path] = canched;
            }

            result.source = source;
            mTextures[name] = result;
        }

        static void LoadAssetTexture (const std::string& path, const std::string& name, int x, int y, int w, int h) {
            TextureDetails result;
            Rectangle source = {};
            source.x = x;
            source.y = y;
            source.width = w;
            source.height = h;

            if (mTextures.find(path) != mTextures.end()) {
                result.texture = mTextures[path].texture;
            }
            else {
                Texture2D texture = LoadTexture(path.c_str());

                result.texture = texture;

                TextureDetails canched = {result.texture, {0, 0, (float) texture.width, (float) texture.height} };
                mTextures[path] = canched;
            }
            result.source = source;
            mTextures[name] = result;

        }
};
#endif //ASSETS_HPP
