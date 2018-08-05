#include "Room_tnnl_plain_4.h"
#include "include.h"

namespace CBN {

// Functions.
void UpdateEvent_tnnl_plain_4(Event* e) {
    float dist;
    int i;
    int temp;
    int pvt;
    String strtemp;
    int j;
    int k;
    int tex;

    Particle* p;
    NPC* n;
    Room* r;
    Event* e2;
    Item* it;
    Emitter* em;
    SecurityCam* sc;
    SecurityCam* sc2;

    String CurrTrigger = "";

    float x;
    float y;
    float z;

    float angle;

    //[Block]
    if (e->room->dist < 10.0 & e->room->dist > 0) {
        e->room->npc[0] = CreateNPC(NPCtypeD, bbEntityX(e->room->obj,true)+1.0, 0.5, bbEntityZ(e->room->obj,true)+1.0);
        e->room->npc[0]->texture = "GFX/npcs/body1.jpg";
        tex = bbLoadTexture(e->room->npc[0]->texture);
        bbEntityTexture(e->room->npc[0]->obj, tex);
        bbFreeTexture(tex);

        bbRotateEntity(e->room->npc[0]->collider, 0, bbEntityYaw(e->room->obj)-(bbRand(20,60)),0, true);

        SetNPCFrame(e->room->npc[0], 19);
        e->room->npc[0]->state = 8;

        //Delete e
        RemoveEvent(e);
    }
    //[End Block]
}

}