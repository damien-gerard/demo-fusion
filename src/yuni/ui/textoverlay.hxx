#ifndef __YUNI_UI_TEXTOVERLAY_HXX__
# define __YUNI_UI_TEXTOVERLAY_HXX__

# include "theme.h"


namespace Yuni
{
namespace UI
{


	inline TextOverlay::TextOverlay():
		pText(),
		pPrevText(),
		pTexture(nullptr),
		pX(0),
		pY(0),
		pAscent(0),
		pFont(Theme::Current()->font),
		// White by default
		pColor(1.0f, 1.0f, 1.0f, 1.0f),
		pMaterial(new Gfx3D::MaterialSurfaceColored("TextColor", 1.0f, 1.0f, 1.0f)),
		pAntiAliased(true),
		pTabWidth(4u),
		pModified(true),
		pDrawOnBaseline(false)
	{
	}


	inline TextOverlay::TextOverlay(const FTFont::Ptr& font):
		pText(),
		pPrevText(),
		pTexture(nullptr),
		pX(0),
		pY(0),
		pAscent(0),
		pFont(font),
		// White by default
		pColor(1.0f, 1.0f, 1.0f, 1.0f),
		pMaterial(new Gfx3D::MaterialSurfaceColored("TextColor", 1.0f, 1.0f, 1.0f)),
		pAntiAliased(true),
		pTabWidth(4u),
		pModified(true),
		pDrawOnBaseline(false)
	{
	}


	inline TextOverlay::TextOverlay(const AnyString& text, float x, float y, const Color::RGBA<float>& color):
		pText(text),
		pPrevText(),
		pTexture(nullptr),
		pX(x),
		pY(y),
		pAscent(0),
		pFont(Theme::Current()->font),
		pColor(color),
		pMaterial(new Gfx3D::MaterialSurfaceColored("TextColor", color)),
		pAntiAliased(true),
		pTabWidth(4u),
		pModified(true),
		pDrawOnBaseline(false)
	{
	}


	inline TextOverlay::~TextOverlay()
	{
	}



	inline TextOverlay& TextOverlay::operator = (const AnyString& newText)
	{
		pModified = true;
		pPrevText = pText;
		pText = newText;
		return *this;
	}

	inline String& TextOverlay::operator << (const AnyString& newText)
	{
		pModified = true;
		pPrevText = pText;
		return pText << newText;
	}


	inline String& TextOverlay::clear()
	{
		pModified = true;
		pPrevText = pText;
		return pText.clear();
	}


	inline String& TextOverlay::text()
	{
		// We are not sure that it will be modified, but it will probably be
		pModified = true;
		pPrevText = pText;
		return pText;
	}

	inline const String& TextOverlay::text() const
	{
		return pText;
	}


	inline void TextOverlay::font(const UI::FTFont::Ptr& font)
	{
		if (font != pFont)
		{
			pModified = true;
			pFont = font;
		}
	}

	inline const UI::FTFont::Ptr& TextOverlay::font() const
	{
		return pFont;
	}


	inline float TextOverlay::width() const
	{
		return nullptr != pTexture ? (float)pTexture->width() : 0.0f;
	}


	inline float TextOverlay::height() const
	{
		return nullptr != pTexture ? (float)pTexture->height() : 0.0f;
	}


	inline void TextOverlay::color(float r, float g, float b)
	{
		pModified = true;
		pColor.assign(r, g, b);
		pMaterial = new Gfx3D::MaterialSurfaceColored("TextColor", r, g, b);
	}

	inline void TextOverlay::color(float r, float g, float b, float a)
	{
		pModified = true;
		pColor.assign(r, g, b, a);
		pMaterial = new Gfx3D::MaterialSurfaceColored("TextColor", r, g, b, a);
	}

	inline void TextOverlay::color(const Color::RGB<float>& color)
	{
		pModified = true;
		pColor = color;
		pMaterial = new Gfx3D::MaterialSurfaceColored("TextColor", color);
	}

	inline void TextOverlay::color(const Color::RGBA<float>& color)
	{
		pModified = true;
		pColor = color;
		pMaterial = new Gfx3D::MaterialSurfaceColored("TextColor", color);
	}


	inline bool TextOverlay::antiAliased() const
	{
		return pAntiAliased;
	}

	inline void TextOverlay::antiAliased(bool newValue)
	{
		pAntiAliased = newValue;
	}


	inline void TextOverlay::texture(const Gfx3D::Texture::Ptr& texture)
	{
		pMaterial = new Gfx3D::MaterialSurfaceTextured(texture);
	}


	inline void TextOverlay::move(float x, float y)
	{
		pX = x;
		pY = y;
	}

	inline float TextOverlay::x() const
	{
		return pX;
	}

	inline float TextOverlay::y() const
	{
		return pY;
	}



} // namespace UI
} // namespace Yuni

#endif // __YUNI_UI_TEXTOVERLAY_HXX__
