SpaceObject::SpaceObject(){

}

/*
 * @MethodName: getCoord
 * @Description:
 *			Returns a coordinate of SpaceObject
 * @Params:
 *			int - 0 for x, 1 for y
 * @Returns:
 *			int - coordinate
 */

int SpaceObject::getCoord(int type){
  return coords[type];
}

/*
 * @MethodName: setCoord
 * @Description:
 *			Sets the x or y coordinate
 * @Params:
 *			int - coordinate to set
 *      int - type of coordinate; 0 for x, 1 for y
 * @Returns:
 *			void
 */

void SpaceObject::setCoord(int set, int type){
  coords[type] = set;
}
