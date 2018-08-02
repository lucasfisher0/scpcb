
#ifndef BBBLITZ3D_H
#define BBBLITZ3D_H

#include "bbsys.h"
#include "../gxruntime/gxscene.h"

extern gxScene *gx_scene;

void bbHWMultiTex(int enable);
int bbHWTexUnits();
int bbGfxDriverCaps3D();
void bbWBuffer(int enable);
void bbDither(int enable);
void bbAntiAlias(int enable);
void bbWireFrame(int enable);
void bbAmbientLight(float r, float g, float b);
void bbClearCollisions();
void bbCaptureWorld();
void bbRenderWorld(float tween);
void bbClearWorld(int e, int b, int t);
int bbActiveTextures();
int bbTrisRendered();
float bbStats3D(int n);
class Texture* bbCreateTexture(int w, int h, int flags, int frames);
class Texture* bbLoadTexture(class BBStr* file, int flags);
class Texture* bbLoadAnimTexture(class BBStr* file, int flags, int w, int h, int first, int cnt);
void bbFreeTexture(class Texture* t);
void bbTextureBlend(class Texture* t, int blend);
void bbTextureCoords(class Texture* t, int flags);
void bbRotateTexture(class Texture* t, float angle);
int bbTextureWidth(class Texture* t);
int bbTextureHeight(class Texture* t);
class BBStr* bbTextureName(class Texture* t);
void bbSetCubeFace(class Texture* t, int face);
void bbSetCubeMode(class Texture* t, int mode);
class gxCanvas* bbTextureBuffer(class Texture* t, int frame);
void bbClearTextureFilters();
class Brush* bbCreateBrush(float r, float g, float b);
void bbFreeBrush(class Brush* b);
void bbBrushColor(class Brush* br, float r, float g, float b);
void bbBrushAlpha(class Brush* b, float alpha);
void bbBrushShininess(class Brush* b, float n);
void bbBrushTexture(class Brush* b, Texture* t, int frame, int index);
class Texture* bbGetBrushTexture(class Brush* b, int index);
void bbBrushBlend(class Brush* b, int blend);
void bbBrushFX(class Brush* b, int fx);
class Entity* bbLoadMesh(class BBStr* f, Entity* p);
class Entity* bbLoadAnimMesh(class BBStr* f, Entity* p);
int bbLoadAnimSeq(class Object* o, BBStr* f);
class Entity* bbCreateMesh(class Entity* p);
class Entity* bbCreateCube(class Entity* p);
class Entity* bbCreateSphere(int segs, Entity* p);
class Entity* bbCreateCylinder(int segs, int solid, Entity* p);
class Entity* bbCreateCone(int segs, int solid, Entity* p);
class Entity* bbCopyMesh(class MeshModel* m, Entity* p);
void bbRotateMesh(class MeshModel* m, float x, float y, float z);
void bbPositionMesh(class MeshModel* m, float x, float y, float z);
void bbFitMesh(class MeshModel* m, float x, float y, float z, float w, float h, float d, int uniform);
void bbFlipMesh(class MeshModel* m);
void bbPaintMesh(class MeshModel* m, Brush* b);
void bbUpdateNormals(class MeshModel* m);
void bbLightMesh(class MeshModel* m, float r, float g, float b, float range, float x, float y, float z);
float bbMeshWidth(class MeshModel* m);
float bbMeshHeight(class MeshModel* m);
float bbMeshDepth(class MeshModel* m);
int bbCountSurfaces(class MeshModel* m);
void bbMeshCullBox(class MeshModel* m, float x, float y, float z, float width, float height, float depth);
class Surface* bbCreateSurface(class MeshModel* m, Brush* b);
class Brush* bbGetSurfaceBrush(class Surface* s);
class Brush* bbGetEntityBrush(class Model* m);
class Surface* bbFindSurface(class MeshModel* m, Brush* b);
void bbPaintSurface(class Surface* s, Brush* b);
int bbAddVertex(class Surface* s, float x, float y, float z, float tu, float tv, float tw);
int bbAddTriangle(class Surface* s, int v0, int v1, int v2);
void bbVertexCoords(class Surface* s, int n, float x, float y, float z);
void bbVertexNormal(class Surface* s, int n, float x, float y, float z);
void bbVertexColor(class Surface* s, int n, float r, float g, float b, float a);
int bbCountVertices(class Surface* s);
int bbCountTriangles(class Surface* s);
float bbVertexX(class Surface* s, int n);
float bbVertexY(class Surface* s, int n);
float bbVertexZ(class Surface* s, int n);
float bbVertexNX(class Surface* s, int n);
float bbVertexNY(class Surface* s, int n);
float bbVertexNZ(class Surface* s, int n);
float bbVertexRed(class Surface* s, int n);
float bbVertexGreen(class Surface* s, int n);
float bbVertexBlue(class Surface* s, int n);
float bbVertexAlpha(class Surface* s, int n);
int bbTriangleVertex(class Surface* s, int n, int v);
class Entity* bbCreateCamera(class Entity* p);
void bbCameraZoom(class Camera* c, float zoom);
void bbCameraRange(class Camera* c, float nr, float fr);
void bbCameraClsColor(class Camera* c, float r, float g, float b);
void bbCameraProjMode(class Camera* c, int mode);
void bbCameraViewport(class Camera* c, int x, int y, int w, int h);
void bbCameraFogColor(class Camera* c, float r, float g, float b);
void bbCameraFogRange(class Camera* c, float nr, float fr);
void bbCameraFogMode(class Camera* c, int mode);
int bbCameraProject(class Camera* c, float x, float y, float z);
float bbProjectedX();
float bbProjectedY();
float bbProjectedZ();
int bbEntityInView(class Entity* e, Camera* c);
class Entity* bbEntityPick(class Object* src, float range);
void bbEntityPickMode(class Object* o, int mode, int obs);
class Entity* bbLinePick(float x, float y, float z, float dx, float dy, float dz, float radius);
float bbPickedX();
float bbPickedY();
float bbPickedZ();
float bbPickedNX();
float bbPickedNY();
float bbPickedNZ();
float bbPickedTime();
class Object* bbPickedEntity();
void* bbPickedSurface();
int bbPickedTriangle();
class Entity* bbCreateLight(int type, Entity* p);
void bbLightColor(class Light* light, float r, float g, float b);
void bbLightRange(class Light* light, float range);
class Entity* bbCreatePivot(class Entity* p);
class Entity* bbCreateSprite(class Entity* p);
void bbRotateSprite(class Sprite* s, float angle);
class Entity* bbLoadMD2(class BBStr* file, Entity* p);
float bbMD2AnimTime(class MD2Model* m);
int bbMD2AnimLength(class MD2Model* m);
int bbMD2Animating(class MD2Model* m);
void bbBSPAmbientLight(class Q3BSPModel* t, float r, float g, float b);
class Entity* bbCreateMirror(class Entity* p);
class Entity* bbCreatePlane(int segs, Entity* p);
void bbTerrainShading(class Terrain* t, int enable);
int bbTerrainSize(class Terrain* t);
class gxChannel* bbEmitSound(class gxSound* sound, Object* o);
class Entity* bbCopyEntity(class Entity* e, Entity* p);
float bbEntityX(class Entity* e, int global);
float bbEntityY(class Entity* e, int global);
float bbEntityYaw(class Entity* e, int global);
float bbEntityZ(class Entity* e, int global);
float bbEntityPitch(class Entity* e, int global);
float bbEntityYaw(class Entity* e, int global);
float bbEntityRoll(class Entity* e, int global);
float bbGetMatElement(class Entity* e, int row, int col);
float bbTFormedX();
float bbTFormedY();
float bbTFormedZ();
float bbVectorYaw(float x, float y, float z);
float bbVectorPitch(float x, float y, float z);
void bbResetEntity(class Object* o);
class Entity* bbGetParent(class Entity* e);
int bbGetEntityType(class Object* o);
void bbEntityBox(class Object* o, float x, float y, float z, float w, float h, float d);
class Object* bbEntityCollided(class Object* o, int type);
int bbCountCollisions(class Object* o);
void bbMoveEntity(class Entity* e, float x, float y, float z);
void bbTurnEntity(class Entity* e, float p, float y, float r, int global);
void bbTranslateEntity(class Entity* e, float x, float y, float z, int global);
void bbPositionEntity(class Entity* e, float x, float y, float z, int global);
void bbRotateEntity(class Entity* e, float p, float y, float r, int global);
void bbPointEntity(class Entity* e, Entity* t, float roll);
void bbAnimateMD2(class MD2Model* m, int mode, float speed, int first, int last, float trans);
void bbAnimate(class Object* o, int mode, float speed, int seq, float trans);
int bbAddAnimSeq(class Object* o, int length);
int bbAnimSeq(class Object* o);
float bbAnimTime(class Object* o);
int bbAnimLength(class Object* o);
int bbAnimating(class Object* o);
void bbEntityParent(class Entity* e, Entity* p, int global);
int bbCountChildren(class Entity* e);
class Entity* bbGetChild(class Entity* e, int index);
class Entity* bbFindChild(class Entity* e, BBStr* t);
void bbPaintEntity(class Model* m, Brush* b);
void bbEntityColor(class Model* m, float r, float g, float b);
void bbEntityAlpha(class Model* m, float alpha);
void bbEntityShininess(class Model* m, float shininess);
void bbEntityTexture(class Model* m, Texture* t, int frame, int index);
void bbEntityBlend(class Model* m, int blend);
void bbEntityFX(class Model* m, int fx);
void bbEntityAutoFade(class Model* m, float nr, float fr);
void bbEntityOrder(class Object* o, int n);
void bbHideEntity(class Entity* e);
void bbShowEntity(class Entity* e);
void bbFreeEntity(class Entity* e);
void bbNameEntity(class Entity* e, class BBStr* t);
class BBStr* bbEntityName(class Entity* e);
class BBStr* bbEntityClass(class Entity* e);

#endif
