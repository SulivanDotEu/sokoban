#include <osg/Geode>
#include <osgViewer/Viewer>
#include <iostream>

int main(void)
{
	// Instantiation d'une g�om�trie 
	osg::ref_ptr<osg::Geometry> carre = new osg::Geometry;

	// Les 4 sommets du carr� sont stock�s dans un Vec3Array 
	osg::ref_ptr<osg::Vec3Array> vertexArray = new osg::Vec3Array;
	vertexArray->push_back(osg::Vec3(0,1,0));
	vertexArray->push_back(osg::Vec3(1,1,0));
	vertexArray->push_back(osg::Vec3(1,0,0));
	vertexArray->push_back(osg::Vec3(0,0,0));

	// Les couleurs � associer aux sommets sont stock�s dans un Vec4Array 
	osg::ref_ptr<osg::Vec4Array> colorArray = new osg::Vec4Array;
	colorArray->push_back(osg::Vec4(1,1,1,1));
	colorArray->push_back(osg::Vec4(1,0,0,1));
	colorArray->push_back(osg::Vec4(0,1,0,1));
	colorArray->push_back(osg::Vec4(0,0,1,1));

	// Le vecteur normal � associer au carr� est stock� dans un Vec3Array 
	osg::ref_ptr<osg::Vec3Array> normalArray = new osg::Vec3Array;
	normalArray->push_back(osg::Vec3(0,0,1));

	// Une couleur par sommet 
	carre->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	// Un vecteur normal pour l'ensemble 
	carre->setNormalBinding(osg::Geometry::BIND_OVERALL);
	// D�finit le tableau des sommets � utiliser 
	carre->setVertexArray(vertexArray);
	// D�finit le tableau des couleurs � utiliser 
	carre->setColorArray(colorArray);
	// D�finit le tableau des vecteurs normaux � utiliser 
	carre->setNormalArray(normalArray);

	// Explicite comment il faut utiliser les sommets pour cr�er la surface requise 
	osg::ref_ptr<osg::DrawElementsUInt> drawElements = new osg::DrawElementsUInt(GL_QUADS);
	drawElements->push_back(3);
	drawElements->push_back(2);
	drawElements->push_back(1);
	drawElements->push_back(0);
	carre->addPrimitiveSet(drawElements);

	// Instancie un noeud de g�om�trie pour accueillir le carr� 
	osg::ref_ptr<osg::Geode> unCarre = new osg::Geode;
	// D�sactive le mod�le d'�clairage
	osg::StateSet* stateset = unCarre->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
	// Ajoute le carr� comme dessin associ� au noeud de g�om�trie 
	unCarre->addDrawable(carre.get());

	// D�finir un viewer 
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	// Positionne et dimensionne la fen�tre
	viewer->setUpViewInWindow(32, 32, 512, 512); // en pixels

	// D�finit une cam�ra 
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	// positione la cam�ra 
	osg::Vec3 eye = osg::Vec3(0,0,1);
	osg::Vec3 center = osg::Vec3(0,0,0);
	osg::Vec3 up = osg::Vec3(0,1,0);
	camera->setViewMatrixAsLookAt(eye,center,up);
	// D�finit un volume de projection 
	camera->setProjectionMatrixAsOrtho(-0.5,1.5,-0.5,1.5,0.5,5);
	// D�finit une viewport o� projeter le mod�le 
	camera->setViewport(new osg::Viewport(10,10,400,400));
	// Annule la cam�ra par d�faut 
	camera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	// D�finit la couleur de fond de la viewport de la cam�ra 
	camera->setClearColor(osg::Vec4(0.5,0.5,0.5,1));

/*	// R�cup�re le positionnement de la cam�ra par d�faut et l'affiche � la console
	viewer->getCamera()->getViewMatrixAsLookAt(eye,center,up);
	std::cout << "eye x : " << eye[0] << std::endl;
	std::cout << "eye y : " << eye[1] << std::endl;
	std::cout << "eye z : " << eye[2] << std::endl;
	std::cout << "center x : " << eye[0] << std::endl;
	std::cout << "center y : " << eye[1] << std::endl;
	std::cout << "center z : " << eye[2] << std::endl;
	std::cout << "up x : " << eye[0] << std::endl;
	std::cout << "up y : " << eye[1] << std::endl;
	std::cout << "up z : " << eye[2] << std::endl;*/

	// D�finit la couleur de fond de la viewport de la cam�ra par d�faut
	viewer->getCamera()->setClearColor(osg::Vec4(0,0.7,0.7,1));

	// Associe le noeud contenant le carr� � la cam�ra 
	camera->addChild(unCarre);

	// D�marre le graphe de sc�ne au noeud correspondant � la cam�ra 
	viewer->setSceneData(camera.get());

	// Lance la boucle de rendu associ�e au viewer d�fini 
	return viewer->run();
}