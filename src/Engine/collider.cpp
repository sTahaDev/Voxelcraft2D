#include "collider.hpp"

void Collider::addCollider(Rectangle &moveableObject, const Rectangle &staticObject)
{
    if (CheckCollisionRecs(moveableObject, staticObject))
    {
        // İki nesne birbirine temas ediyor, çarpışma tespiti edildi.

        // Şimdi, hangi taraftan çarpışma olduğunu kontrol et
        float moveableCenterX = moveableObject.x + moveableObject.width / 2;
        float moveableCenterY = moveableObject.y + moveableObject.height / 2;

        float staticCenterX = staticObject.x + staticObject.width / 2;
        float staticCenterY = staticObject.y + staticObject.height / 2;

        float deltaX = std::abs(moveableCenterX - staticCenterX);
        float deltaY = std::abs(moveableCenterY - staticCenterY);

        float halfMoveableWidth = moveableObject.width / 2;
        float halfMoveableHeight = moveableObject.height / 2;
        float halfStaticWidth = staticObject.width / 2;
        float halfStaticHeight = staticObject.height / 2;

        // X ekseni çarpışma kontrolü
        if (deltaX <= halfMoveableWidth + halfStaticWidth)
        {
            // X ekseni çarpışma tespit edildi.

            // Şimdi Y ekseni çarpışma kontrolü
            if (deltaY <= halfMoveableHeight + halfStaticHeight)
            {
                // Y ekseni çarpışma tespit edildi.

                // İki nesne birbirine tamamen çarpışıyor olarak kabul edilir.
                // İstediğiniz işlemleri gerçekleştirin.

                // Hareketli nesneyi çarpışma noktasından geri çekin
                float overlapX = halfMoveableWidth + halfStaticWidth - deltaX;
                float overlapY = halfMoveableHeight + halfStaticHeight - deltaY;

                if (overlapX < overlapY)
                {
                    // X ekseni çarpışma öncelikli ise
                    if (moveableCenterX < staticCenterX)
                    {
                        moveableObject.x -= overlapX;
                    }
                    else
                    {
                        moveableObject.x += overlapX;
                    }
                }
                else
                {
                    // Y ekseni çarpışma öncelikli ise
                    if (moveableCenterY < staticCenterY)
                    {
                        moveableObject.y -= overlapY;
                    }
                    else
                    {
                        moveableObject.y += overlapY;
                    }
                }
            }
        }
    }
}