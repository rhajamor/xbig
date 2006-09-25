package std;

import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;

/**
 * std::filebuf wrapper.
 * @author hrung
 */
public class StdFileBuf extends NativeObject {

	/**
	 * Internal construtctor
	 */
	public StdFileBuf(InstancePointer pInstance) {
		super(pInstance);
	}
	
	/**
	 * Internal construtctor
	 */
	public StdFileBuf(InstancePointer pInstance, boolean createdByLibrary) {
		super(pInstance, createdByLibrary);
	}

	@Override
	public void delete() {
		// TODO Auto-generated method stub
		throw new UnsupportedOperationException();
	}

}
