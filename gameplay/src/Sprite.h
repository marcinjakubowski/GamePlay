#ifndef SPRITE_H_
#define SPRITE_H_

#include "TileSheet.h"

namespace gameplay
{

class Node;

/**
 * Defines a 2D game visual that may be animated.
 */
class Sprite : public AnimationTarget, public Ref
{
	friend class Node;
	friend class SpriteGroup;

public:

	/**
     * The Sprite should not be flipped.
     */
    static const int FLIP_NONE = 0;

	/**
     * The Sprite should be flipped horizontally.
     */
    static const int FLIP_HORZ = 1;

	/**
     * The Sprite should be flipped vertically.
     */
    static const int FLIP_VERT = 2;

	/**
     * Sprite size animation property. Data=w,h
     */
	static const int ANIMATE_SIZE = 0;

	/**
     * Sprite width animation property. Data=w
     */
	static const int ANIMATE_SIZE_WIDTH = 1;

	/**
     * Sprite height animation property. Data=h
     */
	static const int ANIMATE_SIZE_HEIGHT = 2;

	/**
     * Sprite offset animation property. Data=x,y
     */
	static const int ANIMATE_OFFSET = 3;

	/**
     * Sprite offset X animation property. Data=x
     */
	static const int ANIMATE_OFFSET_X = 4;

	/**
     * Sprite offset Y animation property. Data=y
     */
	static const int ANIMATE_OFFSET_Y = 5;

	/**
     * Sprite source frame animation property. Data=si,fi
	 *
	 * si - Strip index
	 * fi - Frame index
	 *
	 * If the frame is not valid, then the default tile is used.
     */
	static const int ANIMATE_FRAME_INDEX = 6;

	/**
     * Sprite source frame animation property. Data=x,y,w,h
	 *
	 * If the frame is not valid, then the default tile is used.
     */
	static const int ANIMATE_FRAME_SPECIFIC = 7;

	/**
     * Sprite tint animation property. Data=r,g,b,a
     */
	static const int ANIMATE_TINT = 8;

	/**
     * Gets the default untransformed offset from the world origin that sprites will be drawn at.
	 *
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
     *
     * @return The untransformed offset.
     */
	static const Vector2& getDefaultSpriteOffset();

	/**
	 * Sets the default untransformed offset from the world origin that sprites will be drawn at.
	 * 
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
	 *
	 * This will affect any classes based off Sprite such as SpriteGroup.
	 * 
	 * @param offset The untransformed offset.
	 */
	static void setDefaultSpriteOffset(const Vector2& offset);

	/**
	 * Creates a new Sprite for drawing.
	 * 
	 * @param id The ID for the new Sprite.
	 * @param tileSheet The TileSheet that represents this Sprite.
	 * 
	 * @return A new Sprite for drawing.
	 * @script{create}
	 */
	static Sprite* create(const char* id, TileSheet* tileSheet);

	/**
     * Creates a Sprite using the data from the Properties object defined at the specified URL, 
     * where the URL is of the format "<file-path>.<extension>#<namespace-id>/<namespace-id>/.../<namespace-id>"
     * (and "#<namespace-id>/<namespace-id>/.../<namespace-id>" is optional). 
     * 
     * @param url The URL pointing to the Properties object defining the Sprite.
	 * 
	 * @return A new Sprite for drawing.
     * @script{create}
     */
	static Sprite* create(const char* url);

	/**
     * Creates a Sprite from the specified properties object.
     * 
     * @param spriteProperties The properties object defining the Sprite 
	 *  (must have namespace equal to 'sprite').
	 * 
	 * @return A new Sprite for drawing.
     * @script{create}
     */
	static Sprite* create(Properties* spriteProperties);

	/**
     * Gets the identifier for the sprite.
     *
     * @return The sprite identifier.
     */
    const char* getId() const;

	/**
     * Gets the orientation of the sprite.
     *
     * @return The sprite's orientation.
     */
	int getFlip() const;

	/**
	 * Sets the orientation of the sprite.
	 * 
	 * @param flip The sprite orientation.
	 */
	void setFlip(int flip);

	/**
     * Gets the default tile that the sprite will use.
     *
     * @return The sprite's default tile.
     */
	const Rectangle& getDefaultTile() const;

	/**
	 * Sets the default tile that the sprite will use.
	 * 
	 * @param tile The sprite's default tile.
	 */
	void setDefaultTile(const Rectangle& tile);

	/**
     * Gets the untransformed size the sprite will be drawn at.
     *
     * @return The sprite's untransformed size.
     */
	Vector2 getSize() const;

	/**
     * Gets the untransformed width the sprite will be drawn at.
     *
     * @return The sprite's untransformed width.
     */
	float getWidth() const;

	/**
     * Gets the untransformed height the sprite will be drawn at.
     *
     * @return The sprite's untransformed height.
     */
	float getHeight() const;

	/**
	 * Sets the untransformed size the sprite will be drawn at.
	 * 
	 * @param size The untransformed size the sprite will be drawn at.
	 */
	void setSize(const Vector2& size);

	/**
	 * Sets the untransformed size the sprite will be drawn at.
	 * 
	 * @param width The untransformed width the sprite will be drawn at.
	 * @param height The untransformed height the sprite will be drawn at.
	 */
	void setSize(float width, float height);

	/**
     * Sets the untransformed width the sprite will be drawn at.
     *
     * @param width The sprite's untransformed width.
     */
	void setWidth(float width);

	/**
     * Sets the untransformed height the sprite will be drawn at.
     *
     * @param height The sprite's untransformed height.
     */
	void setHeight(float height);

	/**
     * Gets the untransformed offset from the world origin the sprite will be drawn at.
	 *
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
     *
     * @return The sprite's untransformed offset.
     */
	Vector2 getOffset() const;

	/**
     * Gets the untransformed X offset from the world origin the sprite will be drawn at.
     *
     * @return The sprite's untransformed X offset.
	 * 
	 * @see Sprite::getSpriteOffset
     */
	float getOffsetX() const;

	/**
     * Gets the untransformed Y offset from the world origin the sprite will be drawn at.
     *
     * @return The sprite's untransformed Y offset.
	 * 
	 * @see Sprite::getSpriteOffset
     */
	float getOffsetY() const;

	/**
	 * Sets the untransformed offset from the world origin the sprite will be drawn at.
	 * 
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
	 * 
	 * @param offset The sprite's untransformed offset.
	 */
	void setOffset(const Vector2& offset);

	/**
	 * Sets the untransformed offset from the world origin the sprite will be drawn at.
	 * 
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
	 * 
	 * @param x The sprite's untransformed X offset.
	 * @param y The sprite's untransformed Y offset.
	 */
	void setOffset(float x, float y);

	/**
	 * Sets the untransformed X offset from the world origin the sprite will be drawn at.
	 * 
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
	 * 
	 * @param value The sprite's untransformed X offset.
	 */
	void setOffsetX(float value);

	/**
	 * Sets the untransformed Y offset from the world origin the sprite will be drawn at.
	 * 
	 * The world origin is the center of the game window. If the offset is set to be the 
	 * negative half-screen size, then the sprite shows up in the lower-left of the screen.
	 * 
	 * @param value The sprite's untransformed Y offset.
	 */
	void setOffsetY(float value);

	/**
     * Gets the sprite tint.
     *
     * @return The sprite's tint.
     */
	const Vector4& getTint() const;

	/**
	 * Sets the sprite's tint.
	 * 
	 * @param tint The sprite's tint.
	 */
	void setTint(const Vector4& tint);

	//TODO: parallax effect (so layers don't always move when at different depths) //Only needed if camera is not orthographic

	//TODO: scaling based on depth (so layers, even when they are the same size, aren't rendered at different sizes because of different depths) //Only needed if camera is not orthographic

	/**
     * Gets the Node that holds the Sprite.
     *
     * @return The sprite's owning Node.
     */
	Node* getNode() const;

	/**
	 * Sets the Node the holds the Sprite.
	 * 
	 * @param node The node that holds the Sprite.
	 */
	void setNode(Node* node);

	/**
     * Gets the tile sheet that the spritec draws.
     *
     * @return The sprite's tile sheet.
     */
	TileSheet* getTileSheet();

	/**
	 * Draw the sprite.
	 *
	 * @param isolateDraw If each draw call is unique and can't be batched. Batched calls 
	 *  have to be controlled by developer and are not handled internally. Technically, if 
	 *  this is true, this just calls start and finish on the TileSheet.
	 */
	virtual void draw(bool isolateDraw = true);

	/**
     * @see AnimationTarget::getAnimationPropertyComponentCount
     */
    virtual unsigned int getAnimationPropertyComponentCount(int propertyId) const;

    /**
     * @see AnimationTarget::getAnimationProperty
     */
    virtual void getAnimationPropertyValue(int propertyId, AnimationValue* value);

    /**
     * @see AnimationTarget::setAnimationProperty
     */
    virtual void setAnimationPropertyValue(int propertyId, AnimationValue* value, float blendWeight = 1.0f);

protected:

	/**
     * Constructor.
     */
    Sprite(const char* id);

    /**
     * Destructor.
     */
    virtual ~Sprite();

	/**
     * Gets the current animation frame that will be displayed.
     *
     * @return The actual source rectangle of what will be drawn for that sprite.
     */
	const Rectangle& getCurrentAnimationFrame() const;

	/**
     * @see AnimationTarget::getPropertyId
     */
	virtual int getPropertyId(const char* propertyIdStr);

	/**
     * Clones the sprite and returns a new sprite.
     * 
     * @param context The clone context.
     * @return The new cloned sprite.
     */
    virtual Sprite* clone(NodeCloneContext &context);

	/**
     * Copies the data from this Sprite into the given sprite.
     * 
     * @param sprite The sprite to copy the data to.
     * @param context The clone context.
     */
    void cloneInto(Sprite* sprite, NodeCloneContext &context) const;

private:

    Sprite(const Sprite& copy);
    Sprite& operator=(const Sprite&);

	static bool loadSpriteProperties(Sprite* sprite, Properties* spriteProperties, const char* className);

	unsigned int _stripIndex;
	unsigned int _stripFrame;

	std::string _id;
	Node* _node;
	TileSheet* _tileSheet;

protected:

	/**
	 * A boolean flag indicating if the default tile will be used to draw or if frame should be used to draw. Manually changing this can screw up animation.
	 */
	bool _defaultTileInUse;

	/**
	 * The source Rectangle of the TileSheet that will be drawn if _defaultTileInUse is false.
	 */
	Rectangle _frame;

	/**
	 * The sprite's tint.
	 */
	Vector4 _tint;

	/**
	 * Bitwise definition of any "flip" the Sprite has.
	 */
	int _flip;

	/**
	 * The default tile the sprite will use.
	 */
	Rectangle _defaultTile;

	/**
	 * The untransformed width of the sprite.
	 */
	float _width;

	/**
	 * The untransformed height of the sprite.
	 */
	float _height;

	/**
	 * The untransformed X offset of the sprite.
	 */
	float _x;

	/**
	 * The untransformed Y offset of the sprite.
	 */
	float _y;
};

}

#endif