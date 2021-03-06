external shared class Zone;

class EntranceZone : Zone {
    void generate() {
        rooms = array<array<Room@>>(10);
        for (int x=0;x<10;x++) {
            rooms[x] = array<Room@>(10);
            for (int y=0;y<10;y++) {
                @rooms[x][y] = mapGenEntries[0].roomConstructor(this);
                rooms[x][y].position = Vector3f(x*204.8,0,y*204.8);
                rooms[x][y].rotation = 0;
            }
        }
    }
}
