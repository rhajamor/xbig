/* This source file is part of ogre4j
 *     (The JNI bindings for OGRE)
 * For the latest info, see http://www.ogre4j.org/
 * 
 * Copyright (c) 2005 netAllied GmbH, Tettnang
 * Also see acknowledgements in Readme.html
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307, USA, or go to
 * http://www.gnu.org/copyleft/lesser.txt.
 * 
 *
 * NativeObject.java
 * 
 * Version Information
 * -------------------
 * $Revision: 1.1 $
 * $Date: 2006/09/20 11:36:09 $
 * $Author: nenning $
 */
package org.xbig.base;


/**
 * <p>
 * This is ugly, I know. <br></br>
 * But it is quite simple and that is why I do it this way.
 * </p>
 * <br></br>
 * <p>
 * Why does this awful class exist ? <br></br>
 * Consider this situation in the orginal library:
 * <pre>
 * 	template &lt;class T&gt; class A;
 * 	class B;
 * 	class C {
 * 	public:
 * 		A&lt;B&gt; a();
 * 	}
 * </pre>
 * The method C::a() must return an Object. But there is no java
 * class we could instantiate. So we use this class. It is just
 * used as a container for the InstancePointer. When you use such
 * a method, you have to cast it's return type to this class, get
 * it's instance pointer and create an object that implements the
 * generic java interface.
 * </p>
 * <p>
 * eg:
 * <pre>
 * 	C c = new C();
 * 	ParametrizedTemplateReturnPlaceHolder placeHolder;
 * 	placeHolder = (ParametrizedTemplateReturnPlaceHolder) c.a();
 * 	MyImpl a = new MyImpl(placeHolder.getInstacePointer, true);
 * </pre>
 * MyImpl is a class written by the library user. It must implement
 * the Interface org.xbig.IA&lt;org.xbig.IB&gt; (default config.xml)
 * </p>
 * <br></br>
 * <p>
 * At least this is how I thought this should be used. But you just
 * get ClassCastExceptions. So you cannot use methods like the above one.
 * Thus the only use of this class is to have the generated code compileable.
 * </p>
 * @Deprecated Such return types are passed as parameters now.
 * @see org.xbig.base.INativeObject#disconnectFromNativeObject()
 */
@Deprecated
public class ParametrizedTemplateReturnPlaceHolder extends NativeObject {
	public ParametrizedTemplateReturnPlaceHolder(InstancePointer pInstance) {
		super(pInstance, true);
	}
    public void delete(){
	}

	/**
	 * <p>
	 * This constructor is public for internal useage only!
	 * Do not use it!
	 * </p>
	 */
	public ParametrizedTemplateReturnPlaceHolder(org.xbig.base.InstancePointer p, boolean remote) {
		super(p, remote);
	}
}
