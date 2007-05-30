/*
 * Copyright (c) 2006 OneStepAhead AG, Stuttgart. All rights reserved.
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
 * Place - Suite 330, Boston, MA 02111-1307, USA, or goto
 * http://www.gnu.org/copyleft/lesser.txt.
 */

package org.xbig.test.t47;

import junit.framework.JUnit4TestAdapter;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Suite.class)
@Suite.SuiteClasses({BasicTests.class})


public class AllTests {

	// Used for backward compatibility (Ant)
	public static junit.framework.Test suite() {
		return new JUnit4TestAdapter(AllTests.class);
		
	}
	
}
