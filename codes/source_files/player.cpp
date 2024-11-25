#include "../classes/player.hpp"
#include "../classes/projectile.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"
//#include "../classes/screen_fade_object.hpp"
#include "../classes/ui_overlay.hpp"
#include "../classes/explosion_particle.hpp"

Player::Player(Scene* scene, v2 startingPosition)
    : Entity(scene, startingPosition, 10){ //10 de vida por ajora
        mScene->SetPlayer(this);
        mTag="Player";
        
        mShipTextures[0] = Assets::GetTexture("player_left");
        mShipTextures[1] = Assets::GetTexture("player_neutral");
        mShipTextures[2] = Assets::GetTexture("player_right");

        mTexture = &mShipTextures[1];
       
        mBoostersAnimations[0] = Assets::GetAnimation("boosters_left_animation");
        mBoostersAnimations[1] = Assets::GetAnimation("boosters_animation");
        mBoostersAnimations[2] = Assets::GetAnimation("boosters_right_animation");

        mBoosters = &mBoostersAnimations[1];
       
        mSpeed = 10;
        mAttackSpeed = 200.0f / 1000.0f;//1.0f / 5.0f;
        mAttackTime = 0;

        mBoundsSize = {64, 64};
        mBounds = AABB(mPosition , mBoundsSize);

        mRestrictMovementInScene = true;
        
        mHealth=4;
    }

void Player::Tick(float deltaTime) {
    mBoosters->Tick(deltaTime);

    float h = Input::GetHorizontalAxis();
    float v = Input::GetVerticalAxis();

    if(mAttackTime > 0){
        mAttackTime -= deltaTime;
    }

    if(Input::KeyDown(KEY_SPACE) && mAttackTime <= 0) {
        mScene->Add(new Projectile(mScene, mPosition, this, "Enemy"));
        mAttackTime = mAttackSpeed;
    }

    
    if (h!=0 || v!=0) {
        v2 velocity = {h * mSpeed, v * mSpeed};
        Move(velocity);

    }

    if(mHurtTime > 0){
      mHurtTime -= deltaTime;
    }

    //-1 0 1 pero para control Xbox etc se neceista 0 1 2
    //que solo es sumarle 1 xd 
    //pero puede generar problemas por que el control puede tener valores medios .1 .2 etc y tendremos que redondearlo

    int renderIndex = h + 1;
    mTexture = &mShipTextures[renderIndex];
    mBoosters = &mBoostersAnimations[renderIndex];

}

void Player::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;
    
    if(mHurtTime >0){
      mColor = RED;
    }
    else{
      mColor = WHITE;
    }

    DrawTexturePro(mTexture->texture, mTexture->source, destination, {0, 0}, 0, WHITE);
    v2 offset = {0, 64};
    mBoosters->Render(mPosition+offset, {64, 64}); // mBoosters.Render(mPosition+offset, {64, 64}, RED) si ponemos aqui el color (el sea) cambia la textura 
    //asi ponemos mas colores en el booster xd
    
}

void Player::ReceiveDamage(int amount) {
    if(mHurtTime > 0){
      return;
    }
    mHurtTime=0.4f;
    mHealth -= amount;
    if(mHealth <= 0){
      Death();
    }
  
}

void Player::Death(){
    Delete();
    mScene->SetPlayer(nullptr);
    mScene->Add(new ExplosionParticle(mScene, mPosition));
    //mScene->Add(new ScreenFadeObject(mScene));
    UIOverlay* overlay = mScene->GetOverlay("hud");
    if(overlay){
      HudOverlay* hudOverlay = dynamic_cast<HudOverlay*>(overlay);
      hudOverlay->FadeScreen();
    }
}
