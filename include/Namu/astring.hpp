#pragma once

#include <cstdint>

namespace namu {
	enum class style_t : std::uint16_t {};

	constexpr style_t operator&(style_t a, style_t b) noexcept {
		return static_cast<style_t>(static_cast<std::uint16_t>(a) & static_cast<std::uint16_t>(b));
	}
	constexpr style_t operator|(style_t a, style_t b) noexcept {
		return static_cast<style_t>(static_cast<std::uint16_t>(a) | static_cast<std::uint16_t>(b));
	}
	constexpr style_t operator^(style_t a, style_t b) noexcept {
		return static_cast<style_t>(static_cast<std::uint16_t>(a) ^ static_cast<std::uint16_t>(b));
	}
	constexpr style_t operator<<(style_t a, int b) noexcept {
		return static_cast<style_t>(static_cast<std::uint16_t>(a) << b);
	}
	constexpr style_t operator>>(style_t a, int b) noexcept {
		return static_cast<style_t>(static_cast<std::uint16_t>(a) >> b);
	}
	style_t& operator&=(style_t& a, style_t b) noexcept;
	style_t& operator|=(style_t& a, style_t b) noexcept;
	style_t& operator^=(style_t& a, style_t b) noexcept;
	style_t& operator<<=(style_t& a, int b) noexcept;
	style_t& operator>>=(style_t& a, int b) noexcept;

	enum class color : std::uint8_t {
		none,
		black,
		red,
		green,
		yellow,
		blue,
		magenta,
		cyan,
		white,
		bright_black,
		bright_red,
		bright_green,
		bright_yellow,
		bright_blue,
		bright_magenta,
		bright_cyan,
		bright_white,
	};

	static constexpr style_t foreground(color color) noexcept {
		return static_cast<style_t>(color);
	}
	static constexpr color foreground(style_t style) noexcept {
		return static_cast<color>(static_cast<std::uint16_t>(style) & 0x1F);
	}
	static constexpr style_t background(color color) noexcept {
		return static_cast<style_t>(color) << 5;
	}
	static constexpr color background(style_t style) noexcept {
		return static_cast<color>(static_cast<std::uint16_t>(style) >> 5 & 0x1F);
	}

	class achar_t final {
	public:
		constexpr achar_t() noexcept {}
		constexpr achar_t(char byte) noexcept
			: byte(byte) {}
		constexpr achar_t(char byte, style_t style) noexcept
			: byte(byte), style(style) {}
		constexpr explicit achar_t(style_t style) noexcept
			: style(style) {}
		constexpr achar_t(const achar_t& character) noexcept
			: byte(character.byte), style(character.style) {}

	public:
		achar_t& operator=(char character) noexcept;
		achar_t& operator=(const achar_t& character) noexcept;
		constexpr bool operator==(char character) const noexcept {
			return byte == character;
		}
		constexpr bool operator==(const achar_t& character) const noexcept {
			return byte == character.byte;
		}
		constexpr bool operator!=(char character) const noexcept {
			return byte != character;
		}
		constexpr bool operator!=(const achar_t& character) const noexcept {
			return byte != character.byte;
		}
		constexpr bool operator>(char character) const noexcept {
			return byte > character;
		}
		constexpr bool operator>(const achar_t& character) const noexcept {
			return byte > character.byte;
		}
		constexpr bool operator>=(char character) const noexcept {
			return byte >= character;
		}
		constexpr bool operator>=(const achar_t& character) const noexcept {
			return byte >= character.byte;
		}
		constexpr bool operator<(char character) const noexcept {
			return byte < character;
		}
		constexpr bool operator<(const achar_t& character) const noexcept {
			return byte < character.byte;
		}
		constexpr bool operator<=(char character) const noexcept {
			return byte <= character;
		}
		constexpr bool operator<=(const achar_t& character) const noexcept {
			return byte <= character.byte;
		}
		constexpr bool operator&&(char character) const noexcept {
			return byte && character;
		}
		constexpr bool operator&&(const achar_t& character) const noexcept {
			return byte && character.byte;
		}
		constexpr bool operator||(char character) const noexcept {
			return byte || character;
		}
		constexpr bool operator||(const achar_t& character) const noexcept {
			return byte || character.byte;
		}
		constexpr achar_t operator+(char character) const noexcept {
			return achar_t(byte + character, style);
		}
		constexpr achar_t operator-(char character) const noexcept {
			return achar_t(byte + character, style);
		}
		constexpr achar_t operator*(char character) const noexcept {
			return achar_t(byte * character, style);
		}
		constexpr achar_t operator/(char character) const noexcept {
			return achar_t(byte + character, style);
		}
		constexpr achar_t operator%(char character) const noexcept {
			return achar_t(byte % character, style);
		}
		constexpr achar_t operator&(char character) const noexcept {
			return achar_t(byte & character, style);
		}
		constexpr style_t operator&(style_t mask) const noexcept {
			return style & mask;
		}
		constexpr achar_t operator|(char character) const noexcept {
			return achar_t(byte | character, style);
		}
		constexpr style_t operator|(style_t mask) const noexcept {
			return style | mask;
		}
		constexpr achar_t operator^(char character) const noexcept {
			return achar_t(byte ^ character, style);
		}
		constexpr style_t operator^(style_t mask) const noexcept {
			return style ^ mask;
		}
		constexpr achar_t operator<<(char character) const noexcept {
			return achar_t(byte << character, style);
		}
		constexpr achar_t operator>>(char character) const noexcept {
			return achar_t(byte >> character, style);
		}
		constexpr achar_t operator~() const noexcept {
			return achar_t(~byte, style);
		}
		achar_t& operator+=(char character) noexcept;
		achar_t& operator-=(char character) noexcept;
		achar_t& operator*=(char character) noexcept;
		achar_t& operator/=(char character) noexcept;
		achar_t& operator%=(char character) noexcept;
		achar_t& operator&=(char character) noexcept;
		achar_t& operator&=(style_t mask) noexcept;
		achar_t& operator|=(char character) noexcept;
		achar_t& operator|=(style_t mask) noexcept;
		achar_t& operator^=(char character) noexcept;
		achar_t& operator^=(style_t mask) noexcept;
		achar_t& operator<<=(char character) noexcept;
		achar_t& operator>>=(char character) noexcept;
		achar_t& operator++() noexcept;
		achar_t operator++(int) noexcept;
		achar_t& operator--() noexcept;
		achar_t operator--(int) noexcept;
		constexpr achar_t operator-() const noexcept {
			return achar_t(-byte, style);
		}

	public:
		char byte = 0;
		style_t style{};
		std::uint8_t reserved = 0;
	};

	constexpr bool operator==(char byte, const achar_t& character) noexcept {
		return character == byte;
	}
	constexpr bool operator!=(char byte, const achar_t& character) noexcept {
		return character != byte;
	}
	constexpr bool operator>(char byte, const achar_t& character) noexcept {
		return character < byte;
	}
	constexpr bool operator>=(char byte, const achar_t& character) noexcept {
		return character <= byte;
	}
	constexpr bool operator<(char byte, const achar_t& character) noexcept {
		return character > byte;
	}
	constexpr bool operator<=(char byte, const achar_t& character) noexcept {
		return character >= byte;
	}
	constexpr bool operator&&(char byte, const achar_t& character) noexcept {
		return character && byte;
	}
	constexpr bool operator||(char byte, const achar_t& character) noexcept {
		return character || byte;
	}
	constexpr achar_t operator+(char byte, const achar_t& character) noexcept {
		return character + byte;
	}
	constexpr achar_t operator-(char byte, const achar_t& character) noexcept {
		return character - byte;
	}
	constexpr achar_t operator*(char byte, const achar_t& character) noexcept {
		return character * byte;
	}
	constexpr achar_t operator/(char byte, const achar_t& character) noexcept {
		return character / byte;
	}
	constexpr achar_t operator%(char byte, const achar_t& character) noexcept {
		return character % byte;
	}
	constexpr achar_t operator&(char byte, const achar_t& character) noexcept {
		return character & byte;
	}
	constexpr style_t operator&(style_t style, const achar_t& character) noexcept {
		return character & style;
	}
	constexpr achar_t operator|(char byte, const achar_t& character) noexcept {
		return character | byte;
	}
	constexpr style_t operator|(style_t style, const achar_t& character) noexcept {
		return character | style;
	}
	constexpr achar_t operator^(char byte, const achar_t& character) noexcept {
		return character ^ byte;
	}
	constexpr style_t operator^(style_t style, const achar_t& character) noexcept {
		return character ^ style;
	}
	constexpr char operator<<(char byte, const achar_t& character) noexcept {
		return byte << character.byte;
	}
	constexpr char operator>>(char byte, const achar_t& character) noexcept {
		return byte >> character.byte;
	}
}