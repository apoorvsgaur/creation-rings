%Designed by Apoorv Gaur
function varargout = GUI8(varargin)
% GUI8 MATLAB code for GUI8.fig
%      GUI8, by itself, creates a new GUI8 or raises the existing
%      singleton*.
%
%      H = GUI8 returns the handle to a new GUI8 or the handle to
%      the existing singleton*.
%
%      GUI8('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI8.M with the given input arguments.
%
%      GUI8('Property','Value',...) creates a new GUI8 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI8_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI8_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI8

% Last Modified by GUIDE v2.5 23-Apr-2013 21:48:39

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI8_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI8_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI8 is made visible.
function GUI8_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI8 (see VARARGIN)

% Choose default command line output for GUI8
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

set (handles.descrip,'String','Nanomedical approaches to drug delivery center on developing nanoscale particles or molecules to improve drug bioavailability. ');
set (handles.link_a,'String','Nodal/Activin signaling drives self-renewal and tumorigenicity of pancreatic cancer stem cells and provides a target for combined drug therapy.');
set (handles.help_nano,'String','Primary human pancreatic cancer tissue showed no response due to drug delivery. The addition of a pathway inhibitor enhanced delivery of the survival. Inhibition provides a strategy for targeting cancer stem cells. Drug Delivery can only be tested using Nanotechnology');
set (handles.image_h,'String','Self-Renewal');
a=imread('Self_Renewal.png'); 
image(a);  
axis off
% UIWAIT makes GUI8 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI8_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in toLast.
function toLast_Callback(hObject, eventdata, handles)
% hObject    handle to toLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
GUI7

% --- Executes on button press in nexSlide.
function nexSlide_Callback(hObject, eventdata, handles)
% hObject    handle to nexSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ovSlide.
function ovSlide_Callback(hObject, eventdata, handles)
% hObject    handle to ovSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in homeSlide.
function homeSlide_Callback(hObject, eventdata, handles)
% hObject    handle to homeSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toHome.
function toHome_Callback(hObject, eventdata, handles)
% hObject    handle to toHome (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
nanohubGUI_sec008_team24

% --- Executes on button press in toOv.
function toOv_Callback(hObject, eventdata, handles)
% hObject    handle to toOv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
overviewGUI_sec008_team24

% --- Executes on button press in toNext.
function toNext_Callback(hObject, eventdata, handles)
% hObject    handle to toNext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
GUI8

% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes1


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1

%get what the users select
val = get(hObject,'Value');

% Set current data to the selected data set.
switch val;
case 1 % User selects drug delivery.
   set (handles.descrip,'String','Nanomedical approaches to drug delivery center on developing nanoscale particles or molecules to improve drug bioavailability. ');
   set (handles.link_a,'String','Nodal/Activin signaling drives self-renewal and tumorigenicity of pancreatic cancer stem cells and provides a target for combined drug therapy.');
   set (handles.help_nano,'String','Primary human pancreatic cancer tissue showed no response due to drug delivery. The addition of a pathway inhibitor enhanced delivery of the survival. Inhibition provides a strategy for targeting cancer stem cells. Drug Delivery can only be tested using Nanotechnology');
   set (handles.image_h,'String','Self-Renewal');
   a=imread('Self_Renewal.png'); 
   image(a);  
   axis off
case 2 % User selects Molecular Imaging.
   set (handles.descrip,'String','Molecular imaging originated from the field of radiopharmacology due to the need to better understand the fundamental molecular pathways inside organisms in a noninvasive manner.');
   set (handles.link_a,'String','Nodal/Activin signaling drives self-renewal and tumorigenicity of pancreatic cancer stem cells and provides a target for combined drug therapy.');
   set (handles.help_nano,'String','Primary human pancreatic cancer tissue showed no response due to drug delivery. The addition of a pathway inhibitor enhanced delivery of the survival. Inhibition provides a strategy for targeting cancer stem cells. /n Drug Delivery can only be tested using Nanotechnology');
   set (handles.image_h,'String','Self-Renewal');
   a=imread('Self_Renewal.png'); 
   image(a);  
   axis off
case 3 % User selects Microfluids.
   set (handles.descrip,'String','Microfluidics deals with the behavior, precise control and manipulation of fluids that are geometrically constrained to a small, typically sub-millimeter, scale.');
   set (handles.link_a,'String','The differentiation process of embryonic stem cells into cardiomyocytes was investigated with a microfluidic platform which allows for versatile cell seeding arrangements, optical observation access, long-term cell viability, and programmable cyclic stretch.');
   set (handles.help_nano,'String','The study above demonstrates that the microfluidic system contributes to enhanced differentiation. This platform can also be applied to investigate other biological mechanisms. These mechanisms are elements that can only be studied at a nanoscale level.');
   set (handles.image_h,'String','Differentiation');
   a=imread('Cell_Differentiation.png'); 
   image(a);  
   axis off
case 4 % User selects Cell Arrays.
   set (handles.descrip,'String','High-density ordered array involving either living cells (microwells) or printed microarrays (slides).');
   set (handles.link_a,'String','In vitro sensitivity testing of tumor cells could rationalize and improve the choice of chemotherapy and hormone therapy. The developed microfluidic device could be a potential useful tool for high content screening and high throughput screening research.');
   set (handles.help_nano,'String','The sensitivity testing of tumour cells and developed microfluidic devices have to be controlled and maintained at a nano-scale level.');
   set (handles.image_h,'String','Apoptosis');
   a=imread('Apoptosis.png'); 
   image(a);  
   axis off
case 5 % User selects 2D and 3D ECMs and Patterning
   set (handles.descrip,'String','In vivo cells primarily exist embedded within a complex and information-rich environment that contains multiple extracellular matrix (ECM) components, in both 2D and 3D dimensions.');
   set (handles.link_a,'String','A cell migrating in the ECM environment has to pull on the matrix fibers to move. When the matrix is too dense or sparse, the cells react to the situation to their benefit. Studying ECM matrixs is important in processes like wound healing to cancer invasion.');
   set (handles.help_nano,'String','Cell Migration in extracellular matrix environment, is done at the nano-scale level. Without nano-technology, studying the movement of cancer in ECMs would be impossible.');
   set (handles.image_h,'String','Cell Migration');
   a=imread('Cell_Migration.png'); 
   image(a);  
   axis off
end
% Save the handles structure.
guidata(hObject,handles)

% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over popupmenu1.
function popupmenu1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on key press with focus on popupmenu1 and none of its controls.
function popupmenu1_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  structure with the following fields (see UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)
