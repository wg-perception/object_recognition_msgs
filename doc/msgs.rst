.. _msgs:

Messages
########


Object Definition
*****************

An object is uniquely defined by a type and a database in ``ObjectId.msg``:

.. literalinclude:: ../msg/ObjectType.msg

More information is also stored by ``ORK`` in the database. This information can be retrieved in
``ObjectInformation.msg``:

.. literalinclude:: ../msg/ObjectInformation.msg

Recognized Objects
******************

When the objects are recognized, an array of recognized objects is published in ``RecognizedObjectArray.msg``:

.. literalinclude:: ../msg/RecognizedObjectArray.msg

which contains several ``RecognizedObject.msg``:

.. literalinclude:: ../msg/RecognizedObject.msg

Table
*****

There is that object that is pretty useful to recognize and it's called a table. When found with the
:ref:`Tabletop Detector <orktabletop:tabletop>` it publishes those two messages:

.. literalinclude:: ../msg/Table.msg 

.. literalinclude:: ../msg/TableArray.msg
