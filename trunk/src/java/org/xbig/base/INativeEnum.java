package org.xbig.base;

/**
 * 
 * This Interface is needed to make sure all generated Enums
 * provide these two methods.
 * 
 * @see EnumPointer
 */
public interface INativeEnum < T extends INativeEnum > {

    /**
     * Returns the enumeration value for the passed integer.
     */
    T getEnum(int val);

    /**
     * Returns the integer value of this enumeration value.
     */
    int getValue();
}
