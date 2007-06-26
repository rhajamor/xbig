/**
 * 
 */
package org.xbig.test.t23;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.IVector;
import org.xbig.Vector;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		IVector v = new Vector(1, 2, 3);
        IVector sum = new Vector(0, 0, 0);

        // add
        v.operatorAddition(sum, v);
        Assert.assertEquals(2, sum.operatorIndex(0));
        Assert.assertEquals(4, sum.operatorIndex(1));
        Assert.assertEquals(6, sum.operatorIndex(2));
        sum.delete();

        // sub
        sum = new Vector(0, 0, 0);
        v.operatorSubtraction(sum, v);
        Assert.assertEquals(0, sum.operatorIndex(0));
        Assert.assertEquals(0, sum.operatorIndex(1));
        Assert.assertEquals(0, sum.operatorIndex(2));
        sum.delete();

        // mul
        sum = new Vector(0, 0, 0);
        v.operatorMultiplication(sum, v);
        Assert.assertEquals(1, sum.operatorIndex(0));
        Assert.assertEquals(4, sum.operatorIndex(1));
        Assert.assertEquals(9, sum.operatorIndex(2));
        sum.delete();

        // div
        sum = new Vector(0, 0, 0);
        v.operatorDivision(sum, v);
        Assert.assertEquals(1, sum.operatorIndex(0));
        Assert.assertEquals(1, sum.operatorIndex(1));
        Assert.assertEquals(1, sum.operatorIndex(2));
        sum.delete();

        // unary +
        sum = new Vector(0, 0, 0);
        v.operatorAddition(sum);
        Assert.assertEquals(1, sum.operatorIndex(0));
        Assert.assertEquals(2, sum.operatorIndex(1));
        Assert.assertEquals(3, sum.operatorIndex(2));
        sum.delete();

        // unary -
        sum = new Vector(0, 0, 0);
        v.operatorSubtraction(sum);
        Assert.assertEquals(-1, sum.operatorIndex(0));
        Assert.assertEquals(-2, sum.operatorIndex(1));
        Assert.assertEquals(-3, sum.operatorIndex(2));
        sum.delete();

        // prefix ++
        sum = v.operatorIncrement();
        Assert.assertEquals(2, sum.operatorIndex(0));
        Assert.assertEquals(3, sum.operatorIndex(1));
        Assert.assertEquals(4, sum.operatorIndex(2));

        // postfix ++
        sum = new Vector(0, 0, 0);
        v.operatorIncrement(sum, 0);
        Assert.assertEquals(2, sum.operatorIndex(0));
        Assert.assertEquals(3, sum.operatorIndex(1));
        Assert.assertEquals(4, sum.operatorIndex(2));
        sum.delete();
        Assert.assertEquals(3, v.operatorIndex(0));
        Assert.assertEquals(4, v.operatorIndex(1));
        Assert.assertEquals(5, v.operatorIndex(2));

        v.delete();
	}
}
